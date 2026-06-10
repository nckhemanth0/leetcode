class Solution {
public:
    int n;
    int dp[5001][2];  // dp[i][holding]: max profit from day i when holding (1) or not (0)

    int rec(vector<int>& prices, int i, int holding) {
        if (i >= n) return 0;
        if (dp[i][holding] != -1) return dp[i][holding];
        int ans;
        if (holding) {
            // Two choices: sell the stock (and then cooldown by skipping the next day) or hold it.
            int sell = prices[i] + rec(prices, i + 2, 0);  // Sell and then cooldown the next day
            int hold = rec(prices, i + 1, 1);              // Continue holding
            ans = max(sell, hold);
        } else {
            // When not holding: you can either buy or do nothing (skip).
            int buy = -prices[i] + rec(prices, i + 1, 1);   // Buy the stock
            int skip = rec(prices, i + 1, 0);               // Skip buying (rest day)
            ans = max(buy, skip);
        }
        return dp[i][holding] = ans;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return rec(prices, 0, 0);  // Start on day 0, not holding any stock
    }

    // ====== === == === == = ==== = = === == ======= ==== == = = == = == = ==  


    /*
        state:
            0, 1, 2
    */

    int dp1[5001][1001][3];

    int rec(vector<int>& prices, int level, int bought, int state){
        if(level==n){
            return 0;
        }
        if(dp1[level][bought][state]!=-1){
            return dp1[level][bought][state];
        }
        int ans=0;
        if(state==0){
            ans=max(ans,rec(prices,level+1,prices[level],1));
            ans=max(ans,rec(prices,level+1,0,0));
        }else if(state==1){
            if(prices[level]>=bought){
                ans=max(ans,(prices[level]-bought)+rec(prices,level+1,0,2));
            }
            ans=max(ans,rec(prices,level+1,bought,1));
        }else{
            ans=max(ans,rec(prices,level+1,0,0));
        }
        return dp1[level][bought][state]=ans;
    }

    int maxProfit__1(vector<int>& prices) {
        n=prices.size();
        memset(dp1,-1,sizeof(dp1));
        return rec(prices,0,0,0);
    }
};