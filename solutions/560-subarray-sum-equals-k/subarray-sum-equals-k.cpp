class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n,0);
        for(int i=0;i<n;i++){
            pre[i]+=(i>=1?pre[i-1]:0)+nums[i];
        }
        unordered_map<int,int> mp;
        mp[0]=1; // since from 0th index we have to consider sums!
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=mp[pre[i]-k];
            mp[pre[i]]++;
        }
        return ans;
    }

    // TODO: Check other solutions for reference including brute force
};