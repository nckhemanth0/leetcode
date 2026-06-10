class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int rec(vector<int>& coins, int level, int amount){
        if(amount==0){
            return 1;
        }
        if(level==n){
            return 0;
        }
        if(dp[level][amount]!=-1){
            return dp[level][amount];
        }
        int ans=0;
        // take
        if(coins[level]<=amount){
            ans+=rec(coins,level,amount-coins[level]);
        }
        // not take
        ans+=rec(coins,level+1,amount);
        return dp[level][amount]=ans;
    }

    int change(int amount, vector<int>& coins) {
        n=coins.size();
        dp.resize(n+1,vector<int>(amount+1,-1));
        return rec(coins,0,amount);
    }
};