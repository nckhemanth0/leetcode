class Solution {
public:
    unordered_map<int,unordered_map<double,int>> mp;
    long long rec(int level, double val, vector<int>& nums, long long k){
        if(level==nums.size()){
            if(abs(val-k)<=1e-6){
                return 1;
            }
            return 0;
        }
        if(mp.count(level) && mp[level].count(val)){
            return mp[level][val];
        }
        int ans=0;
        ans+=rec(level+1,val*nums[level],nums,k);
        ans+=rec(level+1,val/nums[level],nums,k);
        ans+=rec(level+1,val,nums,k);
        return mp[level][val]=ans;
    }
    int countSequences(vector<int>& nums, long long k) {
        int n=nums.size();
        return rec(0,1,nums,k);
    }
};