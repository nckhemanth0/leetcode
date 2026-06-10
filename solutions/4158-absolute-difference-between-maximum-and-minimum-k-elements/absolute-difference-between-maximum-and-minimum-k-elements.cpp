class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum=0,sum2=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        for(int i=nums.size()-1;i>=0 && i>=nums.size()-k;i--){
            sum2+=nums[i];
        }
        return abs(sum-sum2);
    }
};