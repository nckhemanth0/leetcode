class Solution {
public:

    class state{
    public:
        int w,node; // but as we progress we update w as (distance from source)
    };

    class cmp{
    public:
        bool operator()(const state& a, const state& b) const{
            return a.w>b.w;
        }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<state>> adj(n+1);
        // vector<int> vis(n+1);
        vector<int> dist(n+1, 1e9);

        for(auto x: times){
            adj[x[0]].push_back({x[2],x[1]});
        }
        priority_queue<state, vector<state>, cmp> q;
        dist[k]=0;
        q.push({0,k});
        while(!q.empty()){
            state st1=q.top();
            int w=st1.w, u=st1.node;
            q.pop();
            if(w>dist[u]){
                continue;
            }
            // if(vis[u]){
            //     continue;
            // }
            // vis[u]=1;
            for(auto st2: adj[u]){
                int v=st2.node, w=st2.w;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    q.push({dist[v], v});
                }
            }
        }
        int ans=*max_element(dist.begin()+1,dist.end());
        return ans==1e9?(-1):(ans);
    }


    // ============ Shortest Path Faster Algorithm(SPFA): OTHER NOT MUCH USED ALTERNATIVES WITH BFS and DFS ============
    // NO NEED BUT GOOD TO KNOW
    // KINDA Bellman ford like relaxation
    /*
            1. DFS: 
                (we sort adj list to get to visit all nodes fast)

                                class Solution {
                                public:
                                    // Adjacency list, defined it as per the maximum number of nodes
                                    // But can be defined with the input size as well
                                    vector<pair<int, int>> adj[101];
                                    
                                    void DFS(vector<int>& signalReceivedAt, int currNode, int currTime) {
                                        // If the current time is greater than or equal to the fastest signal received
                                        // Then no need to iterate over adjacent nodes
                                        if (currTime >= signalReceivedAt[currNode]) {
                                            return;
                                        }

                                        // Fastest signal time for currNode so far
                                        signalReceivedAt[currNode] = currTime;
                                        
                                        // Broadcast the signal to adjacent nodes
                                        for (pair<int, int> edge : adj[currNode]) {
                                            int travelTime = edge.first;
                                            int neighborNode = edge.second;
                                            
                                            // currTime + time : time when signal reaches neighborNode
                                            DFS(signalReceivedAt, neighborNode, currTime + travelTime);
                                        }
                                    }
                                    
                                    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
                                        // Build the adjacency list
                                        for (vector<int> time : times) {
                                            int source = time[0];
                                            int dest = time[1];
                                            int travelTime = time[2];
                                            
                                            adj[source].push_back({travelTime, dest});
                                        }
                                        
                                        // Sort the edges connecting to every node
                                        for (int i = 1; i <= n; i++) {
                                            sort(adj[i].begin(), adj[i].end());
                                        }
                                        
                                        vector<int> signalReceivedAt(n + 1, INT_MAX);
                                        DFS(signalReceivedAt, k, 0);
                                        
                                        int answer = INT_MIN;
                                        for (int node = 1; node <= n; node++) {
                                            answer = max(answer, signalReceivedAt[node]);
                                        }
                                        
                                        // INT_MAX signifies atleat one node is unreachable
                                        return answer == INT_MAX ? -1 : answer;
                                    }
                                };

            2. BFS:

                                class Solution {
                                public:
                                    // Adjacency list, defined it as per the maximum number of nodes
                                    // But can be defined with the input size as well
                                    vector<pair<int, int>> adj[101];
                                    
                                    void BFS(vector<int>& signalReceivedAt, int k) {
                                        queue<int> q;
                                        q.push(k);
                                        
                                        // Time for starting node is 0
                                        signalReceivedAt[k] = 0;
                                        
                                        while (!q.empty()) {
                                            int currNode = q.front(); 
                                            q.pop();
                                            
                                            // Broadcast the signal to adjacent nodes
                                            for (pair<int, int> edge : adj[currNode]) {
                                                int time = edge.first;
                                                int neighborNode = edge.second;
                                                
                                                int arrivalTime = signalReceivedAt[currNode] + time;
                                                if (signalReceivedAt[neighborNode] > arrivalTime) {
                                                    // Fastest signal time for neighborNode so far
                                                    // signalReceivedAt[currNode] + time : 
                                                    // time when signal reaches neighborNode
                                                    signalReceivedAt[neighborNode] = arrivalTime;
                                                    q.push(neighborNode);
                                                }
                                            }
                                        }
                                    }
                                    
                                    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
                                        // Build the adjacency list
                                        for (vector<int> time : times) {
                                            int source = time[0];
                                            int dest = time[1];
                                            int travelTime = time[2];
                                            
                                            adj[source].push_back({travelTime, dest});
                                        }

                                        vector<int> signalReceivedAt(n + 1, INT_MAX);
                                        BFS(signalReceivedAt, k);
                                        
                                        int answer = INT_MIN;
                                        for (int i = 1; i <= n; i++) {
                                            answer = max(answer, signalReceivedAt[i]);
                                        }
                                        
                                        // INT_MAX signifies atleat one node is unreachable
                                        return answer == INT_MAX ? -1 : answer;
                                    }
                                };

    */
};