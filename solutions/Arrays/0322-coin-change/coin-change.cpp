class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int rec(vector<int>& coins, int level, int amount){
        if(level==n){
            if(amount==0){
                return 0;
            }else{
                return 1e5;
            }
        }
        if(amount==0){
            return 0;
        }
        if(dp[level][amount]!=-1) return dp[level][amount];
        int ans=1e5;
        // take
        if(coins[level]<=amount){
            ans=min(ans,1+rec(coins,level,amount-coins[level]));
        }
        // not take
        ans=min(ans,rec(coins,level+1,amount));
        return dp[level][amount]=ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        dp.resize(n+1,vector<int>(amount+1,-1));
        int ans=rec(coins,0,amount);
        return ans==1e5?-1:ans;
    }
};