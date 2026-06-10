class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = prices[0];
        int max_profit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            max_profit = max(max_profit, prices[i] - min_so_far);
            min_so_far=min(min_so_far, prices[i]);
        }
        return max_profit;
    }
    int maxProfit_2(vector<int>& prices) {
        int min_so_far = INT_MAX;
        int max_profit = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            if (prices[i] < min_so_far) {
                min_so_far = prices[i];
            } else {
                max_profit = max(max_profit, prices[i] - min_so_far);
            }
        }
        return max_profit;
    }
    int maxProfit_1(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int right_side_max = prices[n - 1];
        // if we are buying at i whats the maximum profit we can get
        for (int i = n - 2; i >= 0; i--) {
            right_side_max = max(right_side_max, prices[i]);
            ans = max(ans, right_side_max - prices[i]);
        }
        return ans;
    }
};
