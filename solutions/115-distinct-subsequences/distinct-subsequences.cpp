class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int rec(string &s, string &t, int i, int j){
        if(i==m){
            if(j==n){
                return 1;
            }else{
                return 0;
            }
        }
        if(j==n){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==t[j]){
            ans+=(rec(s,t,i+1,j+1));
        }
        ans+=(rec(s,t,i+1,j));
        return dp[i][j]=ans;
    }

    int numDistinct(string s, string t) {
        m=s.length(), n=t.length();
        dp.resize(m+1,vector<int>(n+1,-1));
        return rec(s,t,0,0);
    }
};