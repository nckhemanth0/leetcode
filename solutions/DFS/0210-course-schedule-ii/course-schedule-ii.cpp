class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        vector<int> ans;
        for(auto edge: prerequisites){
            indegree[edge[0]]++;
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int u=q.front();
            ans.push_back(u);
            q.pop();
            for(auto v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        for(int i=0;i<n;i++) if(indegree[i]!=0) return {};
        return ans;
    }
};