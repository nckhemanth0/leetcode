class Solution {
    public int minPairSum(int[] nums) {
        int n=nums.length;
        int i=0,j=n-1,ans=Integer.MIN_VALUE;
        Arrays.sort(nums);
        while(i<j){
            ans=Math.max(ans,nums[i++]+nums[j--]);
        }
        return ans;
    }
}

// 2 3 3 5
// 2 3 4 4 5 6