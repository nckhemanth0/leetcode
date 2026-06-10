class Solution {
public:
    int n;
    vector<vector<int>> dp;
    // THINK: i and j to be somewhere between. And k is b/w these 2.... (I initially though of 0 and n-1 visualizations only continuously!)
    int rec(vector<int>& nums, int i, int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        for(int k=i;k<=j;k++){
            ans=max(ans,rec(nums,i,k-1)+rec(nums,k+1,j)+
                            (i-1>=0 ? nums[i-1] : 1) * nums[k] * (j+1<n ? nums[j+1] : 1));
        }
        return dp[i][j]=ans;
    }

    int maxCoins(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return rec(nums,0,n-1);
    }
};