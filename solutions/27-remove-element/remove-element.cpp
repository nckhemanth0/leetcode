class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size(),cnt=n-1,i=0,ans=0;
        while(i<=cnt){
            if(nums[i]==val){
                swap(nums[i],nums[cnt]);
                // we could have just done nums[i] = nums[cnt - 1]; for this problem
                cnt--;
            }else{
                i++;
            }
        }
        return i;
    }
};