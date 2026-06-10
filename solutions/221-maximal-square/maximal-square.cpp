class Solution__1D_DP {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> dp(n+1,0);
        int ans=0;

        for(int i=1;i<=m;i++){
            int prev=0; // old dp[j-1] from previous row = dp[i-1][j-1]
            for(int j=1;j<=n;j++){
                int tmp=dp[j]; // old dp[j] = dp[i-1][j]
                if(matrix[i-1][j-1]=='1'){
                    dp[j]=min({dp[j-1],dp[j],prev})+1;
                    ans=max(ans,dp[j]);
                }else{
                    dp[j]=0;
                }
                prev=tmp;
            }
        }
        return ans*ans;
    }
};


class Solution {
public:

    int dp[301][301];

    int rec(int i, int j, vector<vector<char>>& matrix){
        if(i<0 || j<0){
            return 0; 
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return min({rec(i-1,j,matrix),rec(i,j-1,matrix),rec(i-1,j-1,matrix)})+1;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        // could even do the same below logic in the rec itself without returning & just by calling in some cases like '0' 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=rec(i,j,matrix);
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};