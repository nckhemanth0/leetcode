class Solution {
public:

    /*
        tree condiitons:
            n vetices, n-1 edges
            connected
            DAG / no-cycle
    */

    //  =========== validTree__DFS ============

    bool ans=true;

    void dfs(int u, int par, vector<int> &col, vector<vector<int>> &adj){
        // easrly quit
        if(!ans) return;

        col[u]=1;
        for(auto v: adj[u]){
            if(col[v]==0){
                dfs(v,u,col,adj);
            }else if(v!=par){
                ans=false;
                return;
            }
        }
        col[u]=2;
    }

    bool validTree__DFS(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> col(n,0);
        if(edges.size()!=(n-1)){
            return false;
        }
        for(auto e: edges){
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }
        dfs(0,-1,col,adj);
        for(int i=0;i<n;i++) if(col[i]==0) return false; // multiple components check
        return ans;
    }

    //  =========== validTree__BFS_Without_Kahns ============

    bool validTree__BFS_Without_Kahns(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        if(edges.size()!=(n-1)){
            return false;
        }
        for(auto e: edges){
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }
        vector<int> vis(n,0);
        queue<pair<int,int>> q;
        q.push({0,-1}); vis[0]=1;
        while(!q.empty()){
            auto st=q.front();
            int u=st.first, parent=st.second;
            q.pop();
            for(auto v: adj[u]){
                if(!vis[v]){
                    vis[v]=1;
                    q.push({v,u});
                }else if(v!=parent){
                    return false;
                }
            }
        }
        for(int i=0;i<n;i++) if(vis[i]==0) return false; // multiple components check
        return ans;
    }

    //  =========== validTree__UF ============

    class UF{
    private:
        vector<int> par;
        vector<int> comp_size;
        int num_components;
    public:
        UF(int n){
            reset(n);
        }
        void reset(int n){
            par.resize(n);
            comp_size.resize(n);
            for(int i=0;i<n;i++){
                par[i]=i;
                comp_size[i]=1;
            }
            num_components=n;
        }
        int find(int u){
            if(u!=par[u]){
                return par[u]=find(par[u]);
            }
            return par[u];
        }
        // kept int to confirm successful merge (or checkig if both come under same component)
        int merge(int u, int v){
            int pu=find(u), pv=find(v);
            if(pu!=pv){
                if(comp_size[pu]<comp_size[pv]){
                    swap(pu,pv);
                }
                par[pv]=pu;
                comp_size[pu]+=comp_size[pv];
                num_components--;
            }else{
                return 0;
            }
            return 1;
        }
        int numComponents(){
            return num_components;
        }
    };

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        if(edges.size()!=(n-1)){
            return false;
        }
        UF uf(n);
        for(auto e: edges){
            if(!uf.merge(e[0],e[1])){
                return false;
            }
        }
        return uf.numComponents()==1;
    }

};