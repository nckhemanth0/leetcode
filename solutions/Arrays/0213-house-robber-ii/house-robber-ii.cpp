class Solution {
public:

    int n;
    vector<vector<int>> dp;

    int rec(vector<int>& nums, int level, int first_taken){
        if((first_taken && level>=n-1) || (!first_taken && level>=n)){
            return 0;
        }
        if(dp[level][first_taken]!=-1){
            return dp[level][first_taken];
        }
        int ans=INT_MIN;
        ans=max(ans,rec(nums,level+2,(level==0 || first_taken))+nums[level]);
        ans=max(ans,rec(nums,level+1,first_taken));
        return dp[level][first_taken]=ans;
    }

    int rob(vector<int>& nums) {
        n=nums.size();
        if(n==1){
            return nums[0];
        }
        dp.resize(n+1,vector<int>(2,-1));
        return rec(nums,0,0);
    }

    // ============ ============ ============ ============ ============ ============ ============ 

    // amount of money robbed till level
    int rec__1(vector<int>& nums, int level, int first_taken){
        if((first_taken && level>=n-1) || (!first_taken && level>=n)){
            return 0;
        }
        if(dp[level][first_taken]!=-1){
            return dp[level][first_taken];
        }
        int ans=INT_MIN;
        ans=max(ans,rec__1(nums,level+2,first_taken)+nums[level]);
        ans=max(ans,rec__1(nums,level+1,first_taken));
        return dp[level][first_taken]=ans;
    }

    int rob__1(vector<int>& nums) {
        n=nums.size();
        if(n==1){
            return nums[0];
        }
        dp.resize(n+1,vector<int>(2,-1));
        return max(nums[0]+rec__1(nums,2,1),rec__1(nums,1,0));
    }
    
};