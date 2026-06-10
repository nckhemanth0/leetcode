class Solution {
public:

    class UF{
    public:
        vector<int> par;
        vector<int> comp_size;
        int init_components;
    
        UF(int n){
            init_components=n;
            comp_size.resize(n);
            par.resize(n);
            for(int i=0;i<n;i++){
                par[i]=i;
            }
        }
        int find(int u){
            if(par[u]!=u){
                return par[u]=find(par[u]);
            }
            return u;
        }
        int merge(int u, int v){
            int ru=find(u), rv=find(v);
            if(ru!=rv){
                if(comp_size[ru]<comp_size[rv]){
                    swap(ru,rv);
                }
                par[rv]=ru;
                comp_size[ru]+=comp_size[ru];
                init_components--;
                return 1;
            }
            return 0;
        }
    };

    class state{
    public:
        int w,u,v;
    };

    class cmp{
    public:
        bool operator()(state const &st1, state const &st2) const{
            return st1.w < st2.w;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=m+1;
        vector<state> sorted_weights_edges;
        for(int i=0;i<m;i++){
            for(int j=1;j<m;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                sorted_weights_edges.push_back({dist,i,j});
            }
        }
        sort(sorted_weights_edges.begin(),sorted_weights_edges.end(),cmp());
        UF uf(n);
        int ans=0;
        if(uf.init_components==1){
            return 0;
        }
        for(auto x: sorted_weights_edges){
            if(uf.merge(x.u,x.v)){
                ans+=x.w;
            }
        }
        return ans;
    }

    // TODO: Code Other two solutions based on Prims => Plain prims -> ElogV ~ O(N^2)logN and ptimized prims -> O(N^2)
    // For interviews Krushkals is fine ig!
};