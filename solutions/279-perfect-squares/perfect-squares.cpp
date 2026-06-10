class Solution {
public:

    vector<int> perferctSquares;
    int len;
    vector<vector<int>> dp;
    int rec(int level, int sum){
        if(sum==0){
            return 0;
        }
        if(level==len){
            return 1e5;
        }
        if(dp[level][sum]!=-1){
            return dp[level][sum];
        }
        int ans=1e5;
        if(sum>=perferctSquares[level]){
            ans=min(ans,1+rec(level,sum-perferctSquares[level]));
        }
        ans=min(ans,rec(level+1,sum));
        return dp[level][sum]=ans;
    }

    int numSquares(int n) {
        len=sqrt(n);
        for(int i=1;i<=len;i++){
            perferctSquares.push_back(i*i);
        }
        dp.resize(len,vector<int>(n+1,-1));
        return rec(0,n);
    }
};