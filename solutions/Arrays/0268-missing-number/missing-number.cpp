class Solution {
public:
    // 3 0 1 ?
    // 0 1 2 3
    int missingNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans^=(nums[i]^i);
        }
        ans^=(nums.size());
        return ans;
    }
};