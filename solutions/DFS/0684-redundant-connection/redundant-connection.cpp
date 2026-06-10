class Solution {
public:

    class UF{
    private:
        vector<int> par;
        vector<int> comp_size;
    public:
        UF(int n){
            reset(n);
        }
        void reset(int n){
            par.resize(n);
            for(int i=0;i<n;i++) par[i]=i;
            comp_size.resize(n,1);
        }
        int find(int u){
            if(par[u]!=u){
                return par[u]=find(par[u]);
            }
            return par[u];
        }
        int merge(int u, int v){
            int pu=find(u), pv=find(v);
            if(pu!=pv){
                if(comp_size[pu]<comp_size[pv]){
                    swap(pu,pv);
                }
                comp_size[pu]+=comp_size[pv];
                par[pv]=pu;
            }else{
                return 0;
            }
            return 1;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        UF uf(n+1);
        for(auto e: edges){
            if(!uf.merge(e[0],e[1])){
                return e;
            }
        }
        return {};
    }
};