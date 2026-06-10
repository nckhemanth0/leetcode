class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int streak=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                streak=0;
            }else{
                streak++;
            }
            ans=max(ans,streak);
        }
        return ans;
    }
};