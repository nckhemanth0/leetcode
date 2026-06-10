class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mod_cnt;
        mod_cnt[0]=1;
        int mod=0,ans=0;
        for(int i=0;i<n;i++){
            mod=((mod+nums[i])%k+k)%k;
            if(mod_cnt.count((mod)%k)){
                ans+=mod_cnt[mod];
            }
            mod_cnt[mod]++;
        }
        return ans;
    }
};