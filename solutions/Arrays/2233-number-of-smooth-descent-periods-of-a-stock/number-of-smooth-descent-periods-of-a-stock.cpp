class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long n=prices.size(),cnt=1,ans=0;
        for(int i=1;i<n;i++){
            if(prices[i]!=prices[i-1]-1){
                ans+=(cnt*(cnt+1))/2;
                cnt=1;
            }else{
                cnt++;
            }
        }
        ans+=(cnt*(cnt+1))/2;
        return ans;
    }

    /*
            INTERNAL DP:
                dp[i] = number of smooth descending periods that end at index i

                Now look at the recurrence:

                    If prices[i] == prices[i-1] - 1
                    → every descending period ending at i-1 can be extended
                    → plus the single-element period [prices[i]]
                    → dp[i] = dp[i-1] + 1

                    Otherwise
                    → you can only start a new period at i
                    → dp[i] = 1

                That’s a classic DP recurrence.

                vector<long long> dp(n);
                dp[0] = 1;
                res = 1;

                for (int i = 1; i < n; i++) {
                    if (prices[i] == prices[i-1] - 1)
                        dp[i] = dp[i-1] + 1;
                    else
                        dp[i] = 1;
                    res += dp[i];
                }
    */
};