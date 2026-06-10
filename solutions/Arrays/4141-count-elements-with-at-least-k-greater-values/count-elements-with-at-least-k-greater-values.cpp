class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            auto idx=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
            if(n-idx>=k){
                ans++;
            }
        }
        return ans;
    }
};