class Solution_1 {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        /*
            easy => covered in questions done so far => so not doing
            1. can use bfs or dfs by running search for all unvisited nodes while counting components
            2. undirected and need num components => can use UF
        */
        return 0;
    }
};



class Solution {
public:
    void dfs(vector<int> adjList[], vector<int> &visited, int src) {
        for (int i = 0; i < adjList[src].size(); i++) {
            if (visited[adjList[src][i]] == 0) {
                visited[adjList[src][i]]=1;
                dfs(adjList, visited, adjList[src][i]);
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        if (n == 0) return 0;
      
        int components = 0;
        vector<int> visited(n, 0);
        vector<int> adjList[n];
    
        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                components++;
                visited[i] = 1;
                dfs(adjList, visited, i);
            }
        }
        return components;
    }
};