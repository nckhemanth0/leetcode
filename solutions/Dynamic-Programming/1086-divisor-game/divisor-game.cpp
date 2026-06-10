class Solution {
public:
    vector<int> dp;
    int rec(int n){
        if(dp[n]!=-1){
            return dp[n];
        }
        for(int i=1;i*i<n;i++){
            if(n%i!=0){
                continue;
            }
            if(rec(n-i)==0){
                return dp[n]=true;
            }
        }
        return dp[n]=false;
    }
    bool divisorGame(int n) {
        dp.resize(n+1,-1);
        return rec(n);
    }
};