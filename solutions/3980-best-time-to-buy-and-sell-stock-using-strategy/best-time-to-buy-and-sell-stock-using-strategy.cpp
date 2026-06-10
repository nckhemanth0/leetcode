class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long n=prices.size(),window_sum=0, window_modified_sum=0, total_sum=0, max_window_delta=0;
        for(int i=0;i<n;i++){
            total_sum+=prices[i]*strategy[i];
            // insert
            window_sum+=prices[i]*strategy[i]; // 1
            if(i>=k/2){ // 2
                window_modified_sum+=prices[i];
            }
            // remove
            if(i>=k){
                // i-k is start of previous window
                 window_sum-=prices[i-k]*strategy[i-k]; // 1
                 int prev_window_mid_index=i-(k/2);
                 window_modified_sum-=prices[prev_window_mid_index]; // 2
            }
            // check
            if(i>=k-1){
                max_window_delta=max(max_window_delta, (window_modified_sum-window_sum));
            }
        }
        return total_sum+max_window_delta;
    }
};