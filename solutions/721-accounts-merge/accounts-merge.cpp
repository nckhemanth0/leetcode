class Solution {
public:

    class UF{
    public:
        unordered_map<string,string> par;
        unordered_map<string,int> comp_size;

        string find(string u){
            if(par.find(u)!=par.end() && par[u]!=u){
                return par[u]=find(par[u]);
            }
            return par[u]=u;
        }
        int merge(string u, string v){
            string pu=find(u), pv=find(v);
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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UF uf;
        unordered_map<string,string> email_name_map; // email to name mapping
        unordered_map<string,set<string>> par_comp_map;

        for(auto a: accounts){
            for(int i=1;i<a.size();i++){
                uf.merge(a[1],a[i]);
                email_name_map[a[i]]=a[0];
            }
        }
        int num_comp=0;
        for(auto x: uf.par){
            string child=x.first, root=uf.find(x.second);
            if(child==root){
                num_comp++;
            }
            par_comp_map[root].insert(child);
        }
        vector<vector<string>> ans(num_comp);

        int cnt=0;
        for(auto x: par_comp_map){
            ans[cnt].push_back(email_name_map[x.first]);
            for(auto y: x.second){
               ans[cnt].push_back(y);
            }
            cnt++;
        }
        return ans;
    }
};