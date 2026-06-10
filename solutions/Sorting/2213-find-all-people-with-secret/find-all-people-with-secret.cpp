
/*
                                    ALL APPROACHES Done/Added!

1) SPFA-like BFS (queue + time relaxation): propagate with earliest[] updates; nodes may re-enter queue → worst O(M^2).
2) Bellman–Ford DP: repeat global relaxations over all meetings (N-1 passes) using earliest[] feasibility → O(N*M).
3) Dijkstra / Min-Heap: always process person with smallest known-time first (finalize on pop) → ~ O((N+M) log(N+M)).
4) Sort + Same-Time BFS: sort by time, build graph per time-block, BFS only within that block from current knowers → O(M log M).
5) DSU / Union-Find with Reset: for each time-block, union participants, keep only components connected to 0, reset others → O(M log M) + near-linear DSU.

*/


class Solution {
public:
    struct UF {
        vector<int> p, sz;
        UF(int n): p(n), sz(n,1) { iota(p.begin(), p.end(), 0); }
        int find(int x){ return p[x]==x ? x : p[x]=find(p[x]); }
        void unite(int a,int b){
            a=find(a); b=find(b);
            if(a==b) return;
            if(sz[a]<sz[b]) swap(a,b);
            p[b]=a; sz[a]+=sz[b];
        }
        void reset(int x){ p[x]=x; sz[x]=1; }
    };

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<pair<int,int>>> tm;
        for (auto &m: meetings) tm[m[2]].push_back({m[0], m[1]});

        UF uf(n);
        uf.unite(0, firstPerson);

        for (auto &entry: tm) {
            auto &edges = entry.second;
            set<int> people;

            for (auto &e: edges) {
                uf.unite(e.first, e.second);
                people.insert(e.first);
                people.insert(e.second);
            }

            int root0 = uf.find(0);
            for (int p: people) {
                if (uf.find(p) != root0) uf.reset(p);
            }
        }

        int root0 = uf.find(0);
        vector<int> ans;
        for (int i=0;i<n;i++) if (uf.find(i)==root0) ans.push_back(i);
        return ans;
    }
};

/*
    Dijkstra / Min-Heap Approach:
        Problem: A person can be reached (learn secret) via multiple meetings; order matters.
        Fix: Always process the person with the minimum "time of knowing the secret" first
             (like Dijkstra). Mark visited when popped (finalized), not when pushed.

        Steps:
        1) Build graph: graph[u] stores (meetingTime, v).
        2) Min-heap pq stores (timeKnown, person). Push (0,0) and (0,firstPerson).
        3) Pop smallest time; if already visited, skip. Otherwise mark visited.
        4) For each neighbor (t, v): if t >= timeKnown and not visited[v], push (t, v).
        5) All visited people know the secret.

        Complexity (basic):
            Build graph: O(M)
            Heap ops: each push/pop is log K, K <= (N+M)
            Worst-case pushes can be O(M), so heap work ~ O(M log(N+M))
            Neighbor scans: each visited person scans its adjacency once => O(M)
            Total: O((N+M) log(N+M) + M) ≈ O((N+M) log(N+M))
            Space: O(N + M)

            class Solution {
            public:
                vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
                    unordered_map<int, vector<pair<int,int>>> graph;
                    for (auto &m : meetings) {
                        int x = m[0], y = m[1], t = m[2];
                        graph[x].push_back({t, y});
                        graph[y].push_back({t, x});
                    }

                    // min-heap of (timeKnown, person)
                    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
                    pq.push({0, 0});
                    pq.push({0, firstPerson});

                    vector<char> visited(n, 0);

                    while (!pq.empty()) {
                        auto [timeKnown, u] = pq.top();
                        pq.pop();

                        if (visited[u]) continue;     // already finalized at an earlier time
                        visited[u] = 1;               // finalize u at timeKnown (earliest possible)

                        for (auto [t, v] : graph[u]) {
                            if (!visited[v] && t >= timeKnown) {
                                pq.push({t, v});
                            }
                        }
                    }

                    vector<int> ans;
                    for (int i = 0; i < n; ++i)
                        if (visited[i]) ans.push_back(i);
                    return ans;
                }
            };
*/

/*
    Sort + Same-Time BFS Approach (Official / Optimal Style)

    Idea:
        A secret can only spread through meetings that happen at the SAME time
        once at least one person in that connected component already knows it.
        So we process meetings grouped by time, in increasing order.

    Steps:
        1) Sort all meetings by time.
        2) Group meetings that occur at the same time t.
        3) Maintain knowsSecret[i] = whether person i knows the secret so far.
        4) For each time t:
            a) Build a temporary graph of meetings happening at time t only.
            b) Find all people in this time-group who already know the secret.
            c) Run BFS restricted to this time-group starting from those people.
            d) Everyone reached in this BFS learns the secret.
        5) Collect all people who know the secret.

    Why this works:
        - Secret cannot pass through meetings at different times in one step.
        - Within the same time t, it can spread through all connected people.
        - Resetting the graph per time avoids repeated relaxations.

    Complexity:
        Let N = number of people, M = number of meetings.

        Time:
            - Sorting meetings:            O(M log M)
            - Grouping meetings by time:   O(M)
            - BFS over all time groups:    O(M)
            Total:                         O(M log M)

        Space:
            - knowsSecret array:           O(N)
            - Temporary graph per time:    O(M) worst case
            Total:                         O(N + M)

    Key Comparison:
        - Unlike SPFA-style BFS, nodes are NOT reprocessed across times.
        - Unlike Dijkstra, no heap is needed.
        - This is faster and simpler for this problem’s constraints.

        class Solution {
        public:
            vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                                    int firstPerson) {

                // Sort meetings by time
                sort(meetings.begin(), meetings.end(),
                    [](auto& a, auto& b) { return a[2] < b[2]; });

                // Group meetings with same time
                map<int, vector<pair<int,int>>> sameTimeMeetings;
                for (auto& m : meetings) {
                    sameTimeMeetings[m[2]].push_back({m[0], m[1]});
                }

                vector<bool> knowsSecret(n, false);
                knowsSecret[0] = true;
                knowsSecret[firstPerson] = true;

                // Process time groups in increasing order
                for (auto& [t, group] : sameTimeMeetings) {

                    // Build graph only for this time t
                    unordered_map<int, vector<int>> meet;
                    for (auto& [x, y] : group) {
                        meet[x].push_back(y);
                        meet[y].push_back(x);
                    }

                    // Find starting nodes who already know the secret
                    queue<int> q;
                    unordered_set<int> start;
                    for (auto& [x, y] : group) {
                        if (knowsSecret[x]) start.insert(x);
                        if (knowsSecret[y]) start.insert(y);
                    }

                    // BFS within the same-time component
                    for (int p : start) q.push(p);

                    while (!q.empty()) {
                        int u = q.front(); q.pop();
                        for (int v : meet[u]) {
                            if (!knowsSecret[v]) {
                                knowsSecret[v] = true;
                                q.push(v);
                            }
                        }
                    }
                }

                vector<int> ans;
                for (int i = 0; i < n; ++i)
                    if (knowsSecret[i]) ans.push_back(i);

                return ans;
            }
        };
*/


/*
    BFS Approach:
        Build a graph where edges are meetings labeled with time.
        Maintain earliest[i], the earliest time person i can know the secret.
        Initialize BFS with persons 0 and firstPerson at time 0.
        During BFS, a person may be enqueued multiple times if we find an earlier valid meeting time (time relaxation).
        Hence, this is not a standard BFS (V+E); it behaves like SPFA and can be O(m²) in the worst case.

                class Solution {
                    public:
                        vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                                                int firstPerson) {
                            // For every person, we store the meeting time and label of the person
                            // met.
                            unordered_map<int, vector<pair<int, int>>> graph;
                            for (auto& meeting : meetings) {
                                int x = meeting[0], y = meeting[1], t = meeting[2];
                                graph[x].emplace_back(t, y);
                                graph[y].emplace_back(t, x);
                            }

                            // Earliest time at which a person learned the secret
                            // as per current state of knowledge. If due to some new information,
                            // the earliest time of knowing the secret changes, we will update it
                            // and again process all the people whom he/she meets after the time
                            // at which he/she learned the secret.
                            vector<int> earliest(n, INT_MAX);
                            earliest[0] = 0;
                            earliest[firstPerson] = 0;

                            // Queue for BFS. It will store (person, time of knowing the secret)
                            queue<pair<int, int>> q;
                            q.emplace(0, 0);
                            q.emplace(firstPerson, 0);

                            // Do BFS
                            while (!q.empty()) {
                                auto [person, time] = q.front();
                                q.pop();
                                for (auto [t, nextPerson] : graph[person]) {
                                    if (t >= time && earliest[nextPerson] > t) {
                                        earliest[nextPerson] = t;
                                        q.emplace(nextPerson, t);
                                    }
                                }
                            }

                            // Since we visited only those people who know the secret,
                            // we need to return indices of all visited people.
                            vector<int> ans;
                            for (int i = 0; i < n; ++i) {
                                if (earliest[i] != INT_MAX) {
                                    ans.push_back(i);
                                }
                            }
                            return ans;
                        }
                    };
*/


/*
    Bellman–Ford (DP / Relaxation) Approach:
        Think of earliest[i] as DP: earliest time person i can know the secret.
        Initialize earliest[0] = earliest[firstPerson] = 0, others = INF.
        Repeat (n-1) passes; in each pass relax every meeting (x, y, t) in both directions:
            if earliest[x] <= t, then earliest[y] = min(earliest[y], t)
            if earliest[y] <= t, then earliest[x] = min(earliest[x], t)
        Stop early if a full pass makes no update.
        People with earliest[i] != INF know the secret.

        Time:  O(n * m) worst-case, where m = meetings.size()
        Space: O(n)

            class Solution {
            public:
                vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
                    const int INF = INT_MAX;
                    vector<int> earliest(n, INF);
                    earliest[0] = 0;
                    earliest[firstPerson] = 0;

                    // Bellman-Ford style DP relaxations
                    for (int pass = 0; pass < n - 1; ++pass) {
                        bool changed = false;

                        for (auto &meet : meetings) {
                            int x = meet[0], y = meet[1], t = meet[2];

                            // relax x -> y
                            if (earliest[x] != INF && earliest[x] <= t && earliest[y] > t) {
                                earliest[y] = t;
                                changed = true;
                            }
                            // relax y -> x
                            if (earliest[y] != INF && earliest[y] <= t && earliest[x] > t) {
                                earliest[x] = t;
                                changed = true;
                            }
                        }

                        if (!changed) break; // DP stabilized
                    }

                    vector<int> ans;
                    for (int i = 0; i < n; ++i)
                        if (earliest[i] != INF) ans.push_back(i);

                    return ans;
                }
            };
*/



class Solution1 {
public:

    int find(int u, unordered_map<int,int> &par){
        if(par.count(u)==0) return u;
        if(u!=par[u]){
            return par[u]=find(par[u],par);
        }
        return u;
    }

    void merge(int u, int v, unordered_map<int,int> &par, unordered_map<int,int> &rank){
        int uroot=find(u,par),vroot=find(v,par);
        if(uroot!=vroot){
            if(rank[uroot]<rank[vroot]){
                swap(uroot,vroot);
            }
            rank[uroot]+=rank[vroot];
            par[vroot]=uroot;
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // int size=meetings.size();
        // sort(meetings.begin(),meetings.end(),[](vector<int> a, vector<int> b){
        //     return a[2]<b[2];
        // });
        map<int,vector<pair<int,int>>> timemap; // sorted time
        for(const auto&x: meetings){
            timemap[x[2]].push_back({x[0],x[1]});
        }
        unordered_map<int,int> ansmp;
        timemap[0].push_back({0,firstPerson});
        ansmp[0]=1;
        unordered_map<int,int> par;
        unordered_map<int,int> rank;
        for(const auto&x: timemap){
            int time=x.first;
            auto &v=x.second;
            for(const auto&y: v){
                if(par.count(y.first)==0){
                    par[y.first]=y.first;
                    rank[y.first]=1;
                }
                if(par.count(y.second)==0){
                    par[y.second]=y.second;
                    rank[y.second]=1;
                }
            }
            for(const auto&y: v){
                merge(y.first,y.second,par,rank);
            }
            for(const auto&y: v){
                if(find(y.first, par) == find(0, par)) ansmp[y.first] = 1;
                if(find(y.second, par) == find(0, par)) ansmp[y.second] = 1;
            }
            for(const auto&y: v){
                if(find(y.first,par)!=find(0,par)){
                    par.erase(y.first);
                    rank.erase(y.first);
                    par.erase(y.second);
                    rank.erase(y.second);
                }
            }
        }
        vector<int> ans;
        for(const auto&x: ansmp){
            if(x.second){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};
