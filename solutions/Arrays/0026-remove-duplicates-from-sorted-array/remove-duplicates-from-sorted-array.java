class Solution {
    public int removeDuplicates(int[] nums) {
        int slow=0,fast=0;
        while(fast<nums.length){
            if(fast==0 || nums[fast]!=nums[fast-1]){
                nums[slow++]=nums[fast++];
            }else{
                fast++;
            }
        }
        return slow;
    }
}

/*

1 1 1 1 2 2 2

*/