class Solution {
public:
    vector<vector<int>> graph;
    vector<int> color; 
    vector<int> dp;    

    bool dfs(int node, int destination) {

        if(graph[node].size()==0){
            return node==destination;
        }

        if(dp[node] != -1) {
            return dp[node];
        }

        color[node] = 1;

        bool ans=true;
        for(int nei : graph[node]) {
            if(color[nei]==0){
                if(!dfs(nei, destination)){
                    ans=false;
                    break;
                }
            }else if(color[nei]==1){
                return false;
            }
        }

        color[node] = 2;
        return dp[node]=ans;
    }

    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        graph.assign(n, {});

        for(auto &e : edges) {
            graph[e[0]].push_back(e[1]);
        }

        color.assign(n, 0);
        dp.assign(n, -1);

        return dfs(source, destination);
    }
};