class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        int left=INT_MIN;
        vector<int> suf(n+1,INT_MIN);
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            suf[i]=max(suf[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]>left || nums[i]>suf[i+1]){
                ans.push_back(nums[i]);
            }
            left=max(left,nums[i]);
        }
        return ans;
    }
};