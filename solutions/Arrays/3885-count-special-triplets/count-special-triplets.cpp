class Solution {
public:
    int specialTriplets__(vector<int>& nums) {
        int MOD=1e9+7;
        unordered_map<int,int> prefix,suffix;
        long long n=nums.size(), ans=0;
        for(int i=n-1;i>=1;i--){
            suffix[nums[i]]++;
        }
        prefix[nums[0]]++;
        for(int i=1;i<=n-2;i++){
            suffix[nums[i]]--;
            long long x1=prefix[2LL*nums[i]]%MOD;
            long long x2=suffix[2LL*nums[i]]%MOD;
            ans=ans%MOD+(x1*x2)%MOD;
            ans%=MOD;
            prefix[nums[i]]++;
        }
        return ans;
    }

    // ===== ===== ===== ===== ===== ===== ===== ===== =====

    int specialTriplets(vector<int>& nums) {
        int MOD=1e9+7;
        unordered_map<int,vector<int>> idx_mp;
        long long n=nums.size(), ans=0;
        for(int i=0;i<n;i++){
            idx_mp[nums[i]].push_back(i);
        }
        for(int i=1;i<=n-2;i++){
            int target=nums[i]*2LL;
            if(idx_mp.count(target)==0 || idx_mp[target].size()<=1 || idx_mp[target][0]>=i){
                continue;
            }
            auto split_idx=upper_bound(idx_mp[target].begin(),idx_mp[target].end(),i);
            int left=split_idx-idx_mp[target].begin();
            int right=idx_mp[target].size()-left;
            // important since this current i could also be there in that list which we shd not cnt
            if(nums[i]==0){
                left--;
            }
            ans=(ans+left*1LL*right%MOD)%MOD;
        }
        return ans;
    }
};