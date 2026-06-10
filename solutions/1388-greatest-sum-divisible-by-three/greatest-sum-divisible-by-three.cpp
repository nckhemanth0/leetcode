class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int rec(int level, int mod, vector<int>& nums){
        if(level==n){
            if(mod==0){
                return 0;
            }
            return -1e9;
        }
        if(dp[level][mod]!=-1){
            return dp[level][mod];
        }
        int ans = rec(level+1,(mod+nums[level])%3,nums)+nums[level];
        ans=max(ans,rec(level+1,mod,nums));
        return dp[level][mod]=ans;
    }

    int maxSumDivThree(vector<int>& nums) {
        n=nums.size();
        // for level with req mod what is max sum
        dp.resize(n,vector<int>(3,-1));
        return rec(0,0,nums);
    }
};
