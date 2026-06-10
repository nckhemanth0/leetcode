class Solution {
public:

    // METHOD2: Union find

    class st{
    public:
        double w;
        string node;
    };
    class UF{

    public:
        unordered_map<string,st> par;
        unordered_map<string,int> comp_size;

        st find(string u){
            if(par.find(u)!=par.end()){
                if(par[u].node!=u){
                    st root=find(par[u].node); // returns <weight from par[u] to root, root>
                    root.w*=par[u].w; // par[u].w is u to par[u] weight
                    return par[u]=root;
                }else{
                    return par[u];
                }
            }else{
                return par[u]={1,u};
            }
        }

        int merge(string u, string v, double u_to_v){
            st uroot=find(u), vroot=find(v);
            if(uroot.node!=vroot.node){
                if(comp_size[uroot.node]>=comp_size[vroot.node]){
                    comp_size[uroot.node]+=comp_size[vroot.node];
                    par[vroot.node].node=uroot.node;
                    par[vroot.node].w=(1.0/u_to_v)*(uroot.w/vroot.w);
                }else{
                    comp_size[vroot.node]+=comp_size[uroot.node];
                    par[uroot.node].node=vroot.node;
                    par[uroot.node].w=(u_to_v)*(vroot.w/uroot.w);
                }
                
                return 1;
            }
            return 0;
        }

        void print(){
            for(auto x: par){
                cout<<x.first<<"--> {"<<x.second.w<<", "<<x.second.node<<"}"<<endl;
            }
        }
    };

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        UF uf;
        for(int i=0;i<equations.size();i++){
            uf.merge(equations[i][0], equations[i][1], values[i]);
        }
        vector<double> ans;
        for(auto q: queries){
            if(uf.par.find(q[0])==uf.par.end() || uf.par.find(q[1])==uf.par.end() || 
                uf.find(q[0]).node!=uf.find(q[1]).node
              ){
                ans.push_back(-1.0);
            }else{
                ans.push_back(uf.find(q[0]).w/uf.find(q[1]).w);
            }
        }
        return ans;
    }


    // ============= ============= ============= ============= ============= ============= ============= ============

    class state{
    public:
        double w;
        string v;
    };

    // METHOD2: BFS
    // normal bfs
    // map nodes for strings, weighted and undirected graph
    // since there is no inconsistency, the first discovery is the final dist update for that node. So normal BFS only.. not dijk although its weighted
    // dist can be used as visited
    vector<double> calcEquation__BFS(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<state>> adj;
        unordered_set<string> s;
        for(int i=0;i<equations.size();i++){
            adj[equations[i][0]].push_back({values[i],equations[i][1]});
            adj[equations[i][1]].push_back({1.0/values[i],equations[i][0]});
        }
        vector<double> ans;
        for(auto x: queries){
            if(adj.find(x[0])==adj.end()){
                ans.push_back(-1);
                continue;
            }
            queue<string> q;
            q.push(x[0]);
            unordered_map<string, double> dis;
            dis[x[0]]=1;
            bool found=false;
            while(!q.empty()){
                string u=q.front();
                q.pop();
                if(u==x[1]){
                    ans.push_back(dis[u]);
                    found=true;
                    break;
                }
                for(auto &[w,v]: adj[u]){
                    if(dis.find(v)==dis.end()){
                        dis[v]=dis[u]*w;
                        q.push(v);
                    }
                }
            }    
            if(!found) ans.push_back(-1);
        }    
        return ans;
    }

    // ============= ============= ============= ============= ============= ============= ============= ============

    // METHOD1: Floyd Warshalls algorithm using Maps for non numeric nodes
    vector<double> calcEquation__Floyd_Warshall(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string, double>> dist;
        unordered_set<string> s;
        for(int i=0;i<equations.size();i++){
            dist[equations[i][0]][equations[i][1]]=values[i];
            dist[equations[i][1]][equations[i][0]]=1.0/values[i];
            dist[equations[i][0]][equations[i][0]]=1.0;
            dist[equations[i][1]][equations[i][1]]=1.0;
            s.insert(equations[i][0]);
            s.insert(equations[i][1]);
        }
        for(auto k: s){
            for(auto i: s){
                for(auto j: s){
                    if(dist[i].find(k)!=dist[i].end() && dist[k].find(j)!=dist[k].end()){
                        dist[i][j]=dist[i][k]*dist[k][j];
                    }
                }
            }
        }
        vector<double> ans;
        for(auto q: queries){
            if(dist.find(q[0])==dist.end() || dist[q[0]].find(q[1])==dist[q[0]].end()){
                ans.push_back(-1.0);
            }else{
                ans.push_back(dist[q[0]][q[1]]);
            }
        }
        return ans;
    }

};