class Solution {
    public int numSubarrayBoundedMax(int[] nums, int left, int right) {
        int l=0;
        int last_index=-1;
        int ans=0;
        for(int r=0;r<nums.length;r++){
            if(nums[r]>=left && nums[r]<=right){
                ans+=(r-l+1);
                last_index=r;
            }else if(nums[r]<left){
                ans+=(last_index-l+1);
            }else{
                last_index=r;
                l=r+1;
            }
        }
        return ans;
    }
}

// 1, 2,2,3,