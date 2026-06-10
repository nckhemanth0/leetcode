class Solution {
public:

    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]==nums[i]){
                    return nums[i];
                }
            }
        }
        return 0;
    }

    int repeatedNTimes__map(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto x: nums){
            mp[x]++;
            if(mp[x]>=2) return x;
        }
        return 0;
    }
};