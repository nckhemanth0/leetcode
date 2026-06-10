class Solution {
public:


    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_so_far=INT_MIN;
        int curr_max=0;
        for(int i=0;i<n;i++){
            curr_max=max({nums[i],nums[i]+curr_max}); // max ending at index i
            max_so_far=max(max_so_far,curr_max);
        }
        return max_so_far;
    }

    // ========== ========== TODO: Divide and conquer in Sol ========== ========== ==========

    // ========== ========== DP ========== ========== ==========

    int ans=INT_MIN;
    vector<int> dp;

    int rec(int level, vector<int>& nums){
        if(level==-1){
            return 0;
        }
        if(dp[level]!=-1){
            return dp[level];
        }
        int x=max(nums[level],rec(level-1,nums)+nums[level]);
        ans=max(ans,x);
        return dp[level]=x;
    }

    int maxSubArray__DP(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        rec(n-1,nums);
        return ans;
    }


    // ========= ========= ========= ========= ========= ========= =========
        /*
                        class Solution {
                            public:
                                vector<int> dp;
                                int n;
                                int rec(vector<int>& arr, int level){
                                    if(level<0){
                                        return -1e9;
                                    }
                                    if(dp[level]!=INT_MIN){
                                        return dp[level];
                                    }
                                    return dp[level]=max(arr[level],rec(arr,level-1)+arr[level]);
                                }
                                int maxSubArray(vector<int>& nums) {
                                    n=nums.size();
                                    dp.assign(n,INT_MIN);
                                    int ans=INT_MIN;
                                    for(int i=0;i<n;i++){
                                        ans=max(ans,rec(nums,i));
                                    }
                                    return ans;
                                }
                            };
        */
};