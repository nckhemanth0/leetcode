class Solution {
public:

    int n;
    vector<int> dp;
    int rec(vector<int>& nums,int level){
        if(level>=n){
            return 0;
        }
        if(dp[level]!=-1){
            return dp[level];
        }
        int ans=INT_MIN;
        // taking 
        ans=max(ans,rec(nums,level+2)+nums[level]);
        // not taking
        ans=max(ans,rec(nums,level+1));
        return dp[level]=ans;
    }

    int rob(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,-1);
        return rec(nums,0);
    }

    // ============ ============ ============ ============ ============ ============ ============ 

    int n1;
    vector<vector<int>> dp1;
    int rec__state(vector<int>& nums, int level, int taken){

        if(level==n1){
            return 0;
        }
        if(dp1[level][taken]!=-1){
            return dp1[level][taken];
        }
        int ans=INT_MIN;
        // taking 
        if(!taken){
            ans=max(ans,rec__state(nums,level+1,1)+nums[level]);
        }
        // not taking
        ans=max(ans,rec__state(nums,level+1,0));
        return dp1[level][taken]=ans;
    }

    int rob__state(vector<int>& nums) {
        n1=nums.size();
        dp1.resize(n1+1,vector<int>(2,-1));
        return rec__state(nums,0,0);
    }
};