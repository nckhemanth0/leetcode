class Solution {
public:
    vector<int> cnt;
    vector<int> ans;
    vector<vector<int>> adj;
    int N;
    void dfs1(int u, int p){
        cnt[u]=1;
        for(auto v: adj[u]){
            if(v!=p){
                dfs1(v,u);
                cnt[u]+=cnt[v];
                ans[u]+=ans[v]+cnt[v];
            }
        }
        return;
    }
    void dfs2(int u, int p){
        for(auto v: adj[u]){
            if(v!=p){
                ans[v]=ans[u]-cnt[v]+N-cnt[v];
                dfs2(v,u);
            }
        }
        return;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        N=n;
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        cnt.resize(n,0);
        ans.resize(n,0);
        dfs1(0,-1);
        dfs2(0,-1);
        return ans;
    }
};