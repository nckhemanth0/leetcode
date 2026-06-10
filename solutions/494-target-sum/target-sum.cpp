class Solution {
public:
    int n;
    unordered_map<int,unordered_map<int,int>> dp;
    int rec(vector<int>& nums, int level, int target){
        if(level==n){
            if(target==0){
                return 1;
            }
            return 0;
        }
        if(dp.count(level) && dp[level].count(target)){
            return dp[level][target];
        }
        int ans=0;
        // -
        ans+=rec(nums,level+1,target-nums[level]);
        // +
        ans+=rec(nums,level+1,target+nums[level]);
        return dp[level][target]=ans;

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        return rec(nums,0,target);
    }
};