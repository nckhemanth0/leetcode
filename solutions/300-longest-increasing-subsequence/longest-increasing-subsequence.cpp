class Solution {
public:
    vector<int> dp;
    int rec(vector<int>& nums,int level){
        if(dp[level]!=-1) return dp[level];
        int ans=1;
        for(int start=0;start<level;start++){
            if(nums[start]<nums[level]){
                ans=max(ans,rec(nums,start)+1);
            }
        }
        return dp[level]=ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,rec(nums,i));
        }
        return ans;
    }
};