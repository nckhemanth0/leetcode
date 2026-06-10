class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int curProdMax, curProdMin;
        curProdMax=curProdMin=nums[0];
        int ans=curProdMax;
        for(int i=1;i<n;i++){
            int temp_max=max(max(nums[i],curProdMax*nums[i]),curProdMin*nums[i]);
            curProdMin=min(min(nums[i],curProdMin*nums[i]),curProdMax*nums[i]);
            curProdMax=temp_max;
            ans=max(ans,curProdMax);
        }
        return ans;
    }
};