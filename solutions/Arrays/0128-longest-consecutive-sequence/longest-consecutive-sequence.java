class Solution {
    public int longestConsecutive(int[] nums) {
        int n=nums.length;
        Arrays.sort(nums);
        int ans=0;
        int i=0;
        while(i<n){
            int j=i+1;
            int cnt=1;
            while(j>=1 && j<n){
                if(nums[j]-nums[j-1]==0){
                    j++;
                    continue;
                }else if(nums[j]-nums[j-1]==1){
                    cnt++;
                    j++;
                }else{
                    break;
                }
            }
            ans=Integer.max(ans,cnt);
            i=j;
        }
        return ans;
    }
}

// 1 2 3 4 100 200

// 0 1 1 2 5