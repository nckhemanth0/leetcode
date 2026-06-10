class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n=nums.size();
        long long maxi=LLONG_MIN;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]<maxi){
                ans+=(maxi-nums[i]);
                maxi=nums[i];
            }else{
                maxi=max(1LL*maxi,1LL*nums[i]);
            }
        }
        return ans;
    }
};