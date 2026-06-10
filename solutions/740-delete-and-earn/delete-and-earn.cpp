class Solution {
public:
    vector<int> v;
    vector<int> dp;
    int rec(int level){
        if(level==2e4+1){
            return 0;
        }
        if(dp[level]!=-1){
            return dp[level];
        }
        int ans=INT_MIN;
        if(v[level]>0){
            ans=max(ans,v[level]*level+rec(level+2));
        }
        ans=max(ans,rec(level+1));
        return dp[level]=ans;
    }
    int deleteAndEarn(vector<int>& nums) {
        v.resize(2e4+1,0);
        dp.resize(2e4+1,-1);
        for(auto x: nums){
            v[x]++;
        }
        return rec(1);
    }
};