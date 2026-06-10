class Solution {
public:


    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};

    // class state{
    // public:
    //     int r,c;
    // };
    #define f first
    #define s second

    // =============== =============== ====== METHOD1: Dijkstra ====== =============== ===============

        using node=pair<int, pair<int, int>>;
                        /*
                            Other approach:
                                struct State {
                                    int w;  // current effort to reach (r,c)
                                    int r;
                                    int c;
                                };

                                // min-heap by w
                                struct Cmp {
                                    bool operator()(const State& a, const State& b) const {
                                        return a.w > b.w;  // larger w has lower priority => pq pop gets small weight
                                    }
                                };
                        */
    

    int m,n;

    int minimumEffortPath__Dijkstras(vector<vector<int>>& heights) {
        m=heights.size(), n=heights[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        priority_queue<node, vector<node>, greater<node>> q;
        q.push({0,{0,0}});
        int ans=INT_MAX;
        while(!q.empty()){
            node st=q.top(); // we will be taking min here out of all possible nodes (ques asks the same -> dijk is helping for min pattern here)
            int dist=st.f, r=st.s.f, c=st.s.s;
            q.pop();
            if(r==m-1 && c==n-1){
                ans=dist;
                break;
            }
            if(vis[r][c]){
                continue;
            }
            vis[r][c]=1;
            for(int k=0;k<4;k++){
                int nr=r+x[k], nc=c+y[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc]){
                    int w=abs(heights[r][c]-heights[nr][nc]); // if both values are same then we can move with cost/weight is 0 or distance from source remains same (like 0 in 0-1 bfs)
                    int new_distance=max(dist, w); // in general dijk its addition but here its max variation (distance this far = max weight in path to get this far)
                    q.push({new_distance, {nr,nc}});
                }
            }
        }
        return ans;
    }

    // =============== =============== ====== METHOD2: Binary Search + DFS (can also dO BFS) ====== =============== ===============

    /*
        monotone: if w is ans then we are sure that for any weight (w+1) that exists, we can make path till [m-1][n-1] node 
            so if for w path exists, >w also exists and we have to check if <w exists
            this is a 000001111 monotone
    */

    int dfs(int r, int c, int &maxWeight, vector<vector<int>>& vis, vector<vector<int>>& heights){
        if(r==m-1 && c==n-1){
            return 1;
        }
        vis[r][c]=1;
        for(int k=0;k<4;k++){
            int nr=r+x[k], nc=c+y[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && abs(heights[nr][nc]-heights[r][c])<=maxWeight){
                // keeping global variable is simple way here, so we can just use void here and assign 1 or 0 in base case
                if(dfs(nr,nc,maxWeight,vis,heights)){
                    return 1;
                }
            }
        }
        return 0;
    }

    // Path exists? can We Reach End With Max Weight Mid
    int check(int mid, vector<vector<int>>& heights){
        vector<vector<int>> vis(m, vector<int>(n,0));
        return dfs(0, 0, mid, vis, heights);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        m=heights.size(), n=heights[0].size();
        int lo=0, hi=1e6;
        int ans=hi+1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            // Path exists? can We Reach End With Max Weight Mid
            if(check(mid,heights)==0){
                lo=mid+1;
            }else{
                hi=mid-1;
                ans=min(ans,mid);
            }
        }
        return ans;
    }







    /*

    IMPORTANT DAG LIKE OBSERVATION IN MATRIX!
    ======= WRONG SOLUTION: DIDNT READ QUESTION PROPERLY: THOUGHT CAN ONLY GO RIGHT OR DOWN 
    BUT issue is its not like DAG here to perform DP

            When you can only move right or down in a grid, each move always increases either the row or the column index.
            That means you can never go back to a previous cell → there are no cycles.
            Formally, this defines a Directed Acyclic Graph (DAG), where:

            Each cell is a node.

            Edges go only to the right or down.

            Because it’s acyclic, there’s a topological order (e.g., by increasing row + col) — that’s exactly what allows Dynamic Programming to work.



            ⚠️ If cycles exist

            If you could move in all four directions, or there were teleporting links (like in some graph problems), the graph would have cycles — then plain DP wouldn’t work because:

            You can’t define a consistent order.

            A state might depend on itself indirectly.

            In such cases, you’d use other techniques like:

            BFS (for shortest path in unweighted grid)

            Dijkstra (for weighted)

            Bellman–Ford / Floyd–Warshall (for graphs with possible cycles)

    
                                                // WRONG SOLUTION
                        // int m,n;
                        // vector<vector<int>> dp;

                        // int rec(int r, int c, vector<vector<int>>& grid){
                        //     if(r==0 && c==0){
                        //         return 0;
                        //     }
                        //     if(dp[r][c]!=-1){
                        //         return dp[r][c];
                        //     }
                        //     int up=INT_MAX, left=INT_MAX;
                        //     if(r>=1){
                        //         up=max(rec(r-1,c,grid), abs(grid[r][c]-grid[r-1][c])); // since wer using grid's r-1, i can use check in base case
                        //     }
                        //     if(c>=1){
                        //         left=max(rec(r,c-1,grid), abs(grid[r][c]-grid[r][c-1]));
                        //     }
                        //     return dp[r][c]=min(up, left);
                        // }

                        // int minimumEffortPath(vector<vector<int>>& heights) {
                        //     m=heights.size(), n=heights[0].size();
                        //     dp.resize(m,vector<int>(n,-1));
                        //     return rec(m-1,n-1,heights);
                        // }


            // STILL WRONG SOLUTION BUT GRAH LIKE SAME ABOVE LOGIC FOR DAG EXPLANATION GIVEN ABOVE


                        #include <bits/stdc++.h>
                        using namespace std;

                        // Minimize the maximum edge weight along any path from (0,0) to (m-1,n-1)
                        // Moves allowed: only from up or left into the current cell (DAG)
                        int minimumEffortPath_DAG(vector<vector<int>>& heights) {
                            int m = (int)heights.size(), n = (int)heights[0].size();
                            int V = m * n;

                            auto id = [&](int r, int c) { return r * n + c; };

                            // Build DAG: edges from predecessors -> current
                            vector<vector<pair<int,int>>> adj(V); // (to, weight)
                            vector<int> indeg(V, 0);

                            for (int r = 0; r < m; ++r) {
                                for (int c = 0; c < n; ++c) {
                                    int v = id(r, c);
                                    if (r > 0) {
                                        int u = id(r - 1, c);
                                        int w = abs(heights[r][c] - heights[r - 1][c]);
                                        adj[u].push_back({v, w});
                                        indeg[v]++;
                                    }
                                    if (c > 0) {
                                        int u = id(r, c - 1);
                                        int w = abs(heights[r][c] - heights[r][c - 1]);
                                        adj[u].push_back({v, w});
                                        indeg[v]++;
                                    }
                                }
                            }

                            // DP over topological order (Kahn’s algorithm)
                            const int INF = INT_MAX;
                            vector<int> dp(V, INF);
                            dp[id(0,0)] = 0;

                            queue<int> q;
                            // The unique source in this DAG is (0,0), but we’ll enqueue all indeg 0 nodes for generality.
                            for (int v = 0; v < V; ++v) if (indeg[v] == 0) q.push(v);

                            while (!q.empty()) {
                                int u = q.front(); q.pop();
                                for (auto [v, w] : adj[u]) {
                                    // minimax relaxation: best effort to v is min over predecessors of max(dp[u], w)
                                    if (dp[u] != INF) {
                                        dp[v] = min(dp[v], max(dp[u], w));
                                    }
                                    if (--indeg[v] == 0) q.push(v);
                                }
                            }

                            return dp[id(m-1, n-1)];
                        }

                        // Example driver
                        int main() {
                            vector<vector<int>> heights = {
                                {1, 3, 5},
                                {2, 8, 4},
                                {1, 2, 1}
                            };
                            cout << minimumEffortPath_DAG(heights) << "\n";
                            return 0;
                        }



    */
};