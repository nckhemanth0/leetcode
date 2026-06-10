class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
            int cnt=0;
            int val=nums[j];
            while(j<n && cnt<2 && nums[j]==val){
                nums[i]=nums[j];
                cnt++;
                i++;
                j++;
            }
            while(j<n && nums[j]==val){
                j++;
            }
        }
        return i;
    }
};