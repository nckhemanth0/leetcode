class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],2*edges[i][2]});
        }
        vector<int> dist(n,1e9);
        vector<int> vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
        q.push({0,0});
        dist[0]=0;
        while(!q.empty()){
            auto x=q.top();
            q.pop();
            int u=x.second;
            if(vis[u]){
                continue;
            }
            vis[u]=1;
            for(auto y: adj[u]){
                int v=y.first, w=y.second;
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    q.push({dist[v],v});
                }
            }
        }
        if(dist[n-1]==1e9){
            return -1;
        }
        return dist[n-1];
    }   
};