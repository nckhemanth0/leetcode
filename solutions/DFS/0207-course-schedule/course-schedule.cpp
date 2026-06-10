class Solution {
public:

    int ans=1;

    // Kahn's Algo
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto x: prerequisites){
            g[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int nodeVisited=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            nodeVisited++;
            for(auto v: g[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }

        }
        return nodeVisited==numCourses;
    }

    // ==================== ==================== ====================

    void dfs(int u, vector<int> &col, vector<vector<int>> &g){
        col[u]=1;
        for(auto v: g[u]){
            if(col[v]==0){
                dfs(v,col,g);
            }else if(col[v]==1){
                ans=0;
            }
        }
        col[u]=2;
    }

    bool canFinish__dfs(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(auto x: prerequisites){
            g[x[1]].push_back(x[0]);
        }
        vector<int> col(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(col[i]==0){
                dfs(i,col,g);
            }
        }
        return ans;
    }
};