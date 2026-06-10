class Solution {
public:

    class min_max_deque{
    private:
        deque<int> mini,maxi;
        vector<int> nums;
    public:
        min_max_deque(vector<int>& nums): nums(nums){}
        void push(int rigth_idx){
            // push mini
            while(!mini.empty() && nums[rigth_idx]<=nums[mini.back()]){
                mini.pop_back();
            }
            mini.push_back(rigth_idx);

            // push maxi
            while(!maxi.empty() && nums[rigth_idx]>=nums[maxi.back()]){
                maxi.pop_back();
            }
            maxi.push_back(rigth_idx);
        }
        void pop(int left_idx){
            if(!maxi.empty() && maxi.front()<=left_idx){
                maxi.pop_front();
            }
            if(!mini.empty() && mini.front()<=left_idx){
                mini.pop_front();
            }
        }
        int getMax(){
            return maxi.front();
        }
        int getMin(){
            return mini.front();
        }
    };

    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size(),MOD=1e9+7;
        int l=0,r=0,ans=0;
        min_max_deque q(nums);
        vector<long long> dp(n + 1), pref(n + 1);
        dp[0] = 1;
        pref[0] = 1;
        for(;r<n;r++){
            q.push(r);
            while(nums[q.getMax()]-nums[q.getMin()]>k){
                q.pop(l);
                l++;
            }
            // summation of dp[left](for full l..r window)..to..dp[right](for full just of window) so this considering l...r and l+1...r and l+2....r .... till just r for answers before that valid window
            dp[r] = (pref[r] - ((l-1>=0)?pref[l - 1]:0) + MOD) % MOD;
            pref[r + 1] = (pref[r] + dp[r]) % MOD;
        }
        return (int)(dp[n-1] % MOD);
    }
};


/*
            long long ways = 0;
            // NO PREFIX SUM: directly add dp[L..r]
            for (int start = L; start <= r; ++start) {
                ways += dp[start];
                if (ways >= MOD) ways -= MOD;  // keep it in range
            }

            dp[r + 1] = ways % MOD;
*/