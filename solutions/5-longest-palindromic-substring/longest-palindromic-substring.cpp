class Solution {
public:

    int dp[1001][1001];
    string s;
    int rec(int i, int j){
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MIN;
        if(s[i]==s[j]){
            ans=max(ans,2+rec(i+1,j-1));
        }
        return dp[i][j]=ans;
    }

    string longestPalindrome(string str) {
        s=str;
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    rec(i,j);
                }
            }
        }
        int ans=INT_MIN,start,end;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans<dp[i][j]){
                    ans=dp[i][j];
                    start=i;
                    end=j;
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};