class Solution {
public:

    int m,n;
    vector<vector<int>> dp;
    int rec(string &s1, string &s2, int i, int j){
        if(i==m || j==n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans=1+rec(s1,s2,i+1,j+1);
        }else{
            ans=max(rec(s1,s2,i,j+1),rec(s1,s2,i+1,j));
        }
        return dp[i][j]=ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        m=text1.size(),n=text2.size();
        dp.resize(m+1,vector<int>(n+1,-1));
        return rec(text1,text2,0,0);
    }
};