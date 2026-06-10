class Solution {
public:
    int m,n;
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};
    vector<vector<int>> dp;

    bool check(vector<vector<int>>& matrix, int ii, int jj){
        if(ii>=0 && jj>=0 && ii<m && jj<n){
            return true;
        }
        return false;
    }

    int rec(vector<vector<int>>& matrix, int i, int j){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=1;
        for(int k=0;k<4;k++){
            int ii=i+x[k],jj=j+y[k];
            if(check(matrix,ii,jj) && matrix[ii][jj]>matrix[i][j]){
                ans=max(ans,1+rec(matrix,ii,jj));
            }
        }
        return dp[i][j]=ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size(),n=matrix[0].size();
        dp.resize(m+1,vector<int>(n+1,-1));
        int ans=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,rec(matrix,i,j));
            }
        }
        return ans;
    }
};