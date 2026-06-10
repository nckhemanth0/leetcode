class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
            if(nums[j]%2==0){
                swap(nums[j],nums[i]);
                j++;
                i++;
            }else{
                j++;
            }
        }
        return nums;
    }
};