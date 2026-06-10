class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<int> dp(n,0);
        dp[0]=(obstacleGrid[0][0] == 0) ? 1 : 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[j]=0;
                }else if(j>0){
                    dp[j]=dp[j]+dp[j-1];
                }
            }
        }
        return dp[n-1];
    }

    // ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ======

    int m,n;
    unordered_map<int, unordered_map<int,int>> dp;
    // reach m,n from 0,0
    int rec(vector<vector<int>>& obstacleGrid,int m, int n){
        if(m<0 || n<0 || obstacleGrid[m][n]){
            return 0;
        }
        if(m==0 && n==0){
            return 1;
        }
        if(dp.count(m) && dp[m].count(n)){
            return dp[m][n];
        }
        return dp[m][n]=rec(obstacleGrid,m-1,n)+rec(obstacleGrid,m,n-1);
    }

    int uniquePathsWithObstacles__REC(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size(),n=obstacleGrid[0].size();
        return rec(obstacleGrid,m-1,n-1);
    }
};