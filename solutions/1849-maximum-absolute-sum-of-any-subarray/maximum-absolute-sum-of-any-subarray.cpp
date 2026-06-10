class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=-1e9-1;
        int maxSoFar=-1e9-1;
        int mini=1e9+1;
        int minSoFar=1e9+1;
        for(int i=0;i<n;i++){
            maxi=max(maxi+nums[i],nums[i]);
            maxSoFar=max(maxSoFar,maxi);

            mini=min(mini+nums[i],nums[i]);
            minSoFar=min(minSoFar,mini);
        }
        return max(abs(maxSoFar),abs(minSoFar));
    }
};