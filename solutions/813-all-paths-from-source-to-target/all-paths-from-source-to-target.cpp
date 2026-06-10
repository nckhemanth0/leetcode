class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> indegree(n);
        for(auto list: graph){
            for(auto v: list){
                indegree[v]++;
            }
        }
        queue<int> q;
        q.push(0);
        vector<int> topo;
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            topo.push_back(u);
            for(auto v: graph[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        unordered_map<int,vector<vector<int>>> paths;
        paths[0].push_back({0});
        for(auto u: topo){
            for(auto v: graph[u]){
                for(auto path: paths[u]){
                    path.push_back(v);
                    paths[v].push_back(path);
                }
            }
        }
        return paths[n-1];
    }
};


/*

class Solution__ {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int n;
    void dfs(int u, vector<vector<int>>& graph){
        if(u==n-1){
            ans.push_back(path);
        }
        for(auto v: graph[u]){
            path.push_back(v);
            dfs(v,graph);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        path.push_back(0);
        dfs(0,graph);
        return ans;
    }
};

*/