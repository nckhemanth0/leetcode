class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n=nums.length;
        Arrays.sort(nums);
        List<List<Integer>> ans =new ArrayList<>();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1,k=n-1,target=-nums[i];
            while(j<k){
                if(j>i+1 && nums[j]==nums[j-1]){
                    j++;
                    continue;
                }
                int sum=nums[j]+nums[k];
                if(sum==target){
                    ans.add(List.of(-target,nums[j],nums[k]));
                    j++;k--;
                }else if(sum<target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return ans;
    }
}