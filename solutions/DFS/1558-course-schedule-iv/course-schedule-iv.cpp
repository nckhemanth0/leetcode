class Solution {
public:

    // ===================== floyd warshall ========================

    vector<bool> checkIfPrerequisite__(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int INF=1e9;
        vector<vector<int>> g(n, vector<int>(n,INF));
        for(auto e: prerequisites){
            g[e[0]][e[1]]=1;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    // can even use or operator here by using bool (INF will be 0)
                    // g[i][j]= g[i][j] || (g[i][k] && g[k][j]); 
                    g[i][j]=min({g[i][j],g[i][k]+g[k][j]}); 
                }
            }
        }
        vector<bool> ans;
        for(auto q: queries){
            // given both q0, q1 are not same
            if(g[q[0]][q[1]]==INF){
                ans.push_back(false);
            }else{
                ans.push_back(true);
            }
        }
        return ans;
    }
    // TC: N^3+Q, MC: N^2


// =========== =========== Best TC: Optimized version of kahns code below!! using bitset =========== ===========

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<vector<int>> g(n);
        vector<int> indegree(n,0);
        vector<bitset<100>> reachable(n);

        for(auto e: prerequisites){
            g[e[0]].push_back(e[1]);
            indegree[e[1]]++;
            reachable[e[1]].set(e[0]);
        }
        
        queue<int> q;
        vector<int> topo;
        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v: g[u]){
                // we can even add this below block above the for or inside like here, anything works!
                reachable[v] = reachable[v] | reachable[u];
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        for(auto q: queries){
            ans.push_back(reachable[q[1]][q[0]]);
        }
        return ans;
    }
    /*
        Time: ~ O(N^2)+Q
            Graph construction: O(E) (edges).
            Topological sort: O(N + E).
            Query handling: O(Q).
        Space: O(N^2) (bitsets for N courses, each with N bits).
    */


    // =========== =========== =========== Kahns algo =========== =========== =========== ===========

    vector<bool> checkIfPrerequisite__Khans_unoptimized(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<vector<int>> g(n);
        vector<int> indegree(n,0);
        for(auto e: prerequisites){
            g[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        queue<int> q;
        vector<int> topo;
        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
        unordered_map<int,unordered_set<int>> mp;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v: g[u]){
                // we can even add this below block above the for or inside like here, anything works!
                mp[v].insert(u);
                for(auto x: mp[u]){
                    mp[v].insert(x);
                }
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        for(auto q: queries){
            ans.push_back(mp[q[1]].contains(q[0]));
        }
        return ans;
    }
    // TC: N^3+Q, MC: N^2

};