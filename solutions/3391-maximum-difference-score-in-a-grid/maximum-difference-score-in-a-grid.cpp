class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> pre_min(m+1,vector<int>(n+1,INT_MAX));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pre_min[i+1][j+1]=min({pre_min[i][j+1],pre_min[i+1][j],grid[i][j]});
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,grid[i][j]-min(pre_min[i][j+1],pre_min[i+1][j]));
            }
        }
        return ans;
    }
};