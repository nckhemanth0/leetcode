class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int rec(vector<int>& nums,int level,int sum){
        if(sum==0){
            return 1;
        }
        if(level==n){
            return 0;
        }
        if(dp[level][sum]!=-1) return dp[level][sum];
        bool ans=0;
        if(nums[level]<=sum){
            ans|=rec(nums,level+1,sum-nums[level]);
        }
        ans|=rec(nums,level+1,sum);
        return dp[level][sum]=ans;
    }

    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1){
            return 0;
        }
        dp.resize(n+1,vector<int>(sum+1,-1));
        return rec(nums,0,sum/2);
    }
};