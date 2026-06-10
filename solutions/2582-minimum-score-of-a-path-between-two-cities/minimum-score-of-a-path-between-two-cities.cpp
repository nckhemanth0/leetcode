class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> vis;
    int ans=INT_MAX;
    void dfs(int u, vector<vector<int>>& roads){
        vis[u]=1;
        for(auto v: adj[u]){
            ans=min(ans,v.first);
            if(!vis[v.second]){
                dfs(v.second,roads);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        adj.resize(n+1,vector<pair<int,int>>());
        vis.resize(n+1,0);
        for(int i=0;i<roads.size();i++){
            auto edge=roads[i];
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({w,v});
            adj[v].push_back({w,u});
        }
        dfs(1,roads);
        return ans;
    }
};