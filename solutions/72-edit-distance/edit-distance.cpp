class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int rec(string &word1, string &word2, int i, int j){
        if(i==m){
            return n-j; 
        }
        if(j==n){
            return m-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=1e5;
        if(word1[i]==word2[j]){
            ans=min(ans,rec(word1,word2,i+1,j+1));
        }
        ans=min({ans,1+rec(word1,word2,i,j+1),1+rec(word1,word2,i+1,j),1+rec(word1,word2,i+1,j+1)}); // add, delete and replace cases
        return dp[i][j]=ans;
    }

    int minDistance(string word1, string word2) {
        m=word1.size(), n=word2.size();
        dp.resize(m+1,vector<int>(n+1,-1));
        return rec(word1,word2,0,0);
    }
};