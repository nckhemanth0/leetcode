class Solution {
public:
    vector<vector<int>> dp;
    int rec(vector<vector<int>>& grid, int i, int j){ // maximum summ till (i,j)
        if(i<0 || j<0){
            return INT_MAX;
        }
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=min(rec(grid,i-1,j),rec(grid,i,j-1))+grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        dp.resize(m,vector<int>(n,-1));
        return rec(grid,m-1,n-1);
    }
};