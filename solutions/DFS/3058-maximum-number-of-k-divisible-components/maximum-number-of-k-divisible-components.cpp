class Solution {
public:

    vector<long long> subtree_sum;
    vector<vector<int>> adj;
    long long sum=0;
    long long ans=0;

    void rec(int u, int par, int k, vector<vector<int>> &adj, vector<int> &values){
        subtree_sum[u]=values[u]%k;
        for(auto v: adj[u]){
            if(v!=par){
                rec(v,u,k,adj,values);
                subtree_sum[u]=(subtree_sum[u]+subtree_sum[v])%k;
            }
        }
        if(subtree_sum[u]%k==0 && (sum-(subtree_sum[u])%k+k)%k==0){
            ans++;
        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.resize(n);
        subtree_sum.resize(n);
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<values.size();i++){
            sum=(sum+values[i]%k)%k;
        }    
        rec(0,-1,k,adj,values);
        return ans;
    }
};