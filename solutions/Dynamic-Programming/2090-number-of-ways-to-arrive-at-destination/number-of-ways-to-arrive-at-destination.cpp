// we cant use ways in heap state like dist (did before with tuple): since path1 can push 1way, path can push 2way => but we cant add both => so glbal state is needed

class Solution {
public:
    using ll=long long;
    using ti=tuple<int,int,int>;
    using pl=pair<ll,ll>;
    int mod=1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pl>> adj(n,vector<pl>());
        for(auto x: roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        vector<ll> dist(n+1,LLONG_MAX);
        // vector<int> vis(n+1,0);
        vector<ll> ways(n+1,0);
        priority_queue<pl,vector<pl>,greater<>> pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto top=pq.top();
            ll du=top.first;
            ll u=top.second;
            pq.pop();
            if(u==(n-1)){
                return ways[n-1];
            }
            // if(vis[u]){
            //     continue;
            // }
            // vis[u]=1;
            if(du != dist[u]) continue;
            for(auto &[v,w]: adj[u]){
                if(du+w<dist[v]){
                    dist[v]=du+w;
                    pq.push({dist[v],v});
                    ways[v]=ways[u];
                }else if(du+w==dist[v]){
                    ways[v]=(ways[v]%mod+ways[u]%mod)%mod;
                }
            }
        }
        return 0;
    }
};