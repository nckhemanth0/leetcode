class Solution {
public:

    int m,n,k;
    vector<vector<vector<int>>> dp;
    int modulo=1e9+7;;
    int rec(int i, int j, int mod, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }
        if(i==0 && j==0){
            if((grid[i][j]+mod)%k==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][j][mod]!=-1){
            return dp[i][j][mod];
        }

        return dp[i][j][mod]=(rec(i-1,j,(grid[i][j]+mod)%k,grid)%modulo+rec(i,j-1,(grid[i][j]+mod)%k,grid)%modulo)%modulo;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k1) {
        m=grid.size();
        n=grid[0].size();
        k=k1;
        dp.resize(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return rec(m-1,n-1,0,grid);
    }
};