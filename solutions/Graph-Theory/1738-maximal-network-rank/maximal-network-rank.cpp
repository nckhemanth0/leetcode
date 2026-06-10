class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);
        vector<vector<int>> matrix(n, vector<int>(n,0));
        for(auto e: roads){
            degree[e[0]]++;
            degree[e[1]]++;
            matrix[e[0]][e[1]]=1;
            matrix[e[1]][e[0]]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,(degree[i]+degree[j]-matrix[i][j]));
            }
        }
        return ans;
    }
};