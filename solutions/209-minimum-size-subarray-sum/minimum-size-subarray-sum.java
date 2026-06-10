class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n=nums.length;
        int sum=0,ans=Integer.MAX_VALUE,l=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>=target){
                ans=Integer.min(ans,(r-l+1));
                sum-=nums[l++];
            }
        }
        return ans==Integer.MAX_VALUE?0:ans;
    }
}