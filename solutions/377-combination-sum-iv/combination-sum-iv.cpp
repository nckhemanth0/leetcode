class Solution {
public:

    int n;
    vector<int> dp;
    int rec(vector<int>& nums, int target){
        // cout<<"level: "<<level<<" target: "<<target<<endl;
        if(target==0){
            // for(auto x: v){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            return 1;
        }
        // if(level==n){
        //     return 0;
        // }
        if(dp[target]!=-1) return dp[target];
        int ans=0;
        for(int i=0;i<n;i++){
            if(target>=nums[i]){
                // v.push_back(nums[i]);
                ans+=rec(nums,target-nums[i]);
                // v.pop_back();
            }
        }
        // ans+=rec(nums,level+1,target,v);
        return dp[target]=ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        // vector<int> v;
        dp.resize(target+1,-1);
        return rec(nums,target);
    }
};