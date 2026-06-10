class Solution {
public:
    int n;
    vector<int> dp;
    int rec(string &s, int level){
        if(level==n){
            return 1;
        }
        if(dp[level]!=-1) return dp[level];
        int ans=0;
        // take 1
        if(s[level]!='0'){
            ans+=rec(s,level+1);
        }
        // take 2
        if(level<=n-2 && (s[level]=='1' || (s[level]=='2' && s[level+1]<='6'))){
            ans+=rec(s,level+2);
        }
        return dp[level]=ans;
    }

    int numDecodings(string &s) {
        n=s.length();
        dp.resize(n+1,-1);
        return rec(s,0);
    }
};