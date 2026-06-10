class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int x=0;
        vector<bool> ans;
        for(int i=0;i<nums.size();i++){
            x=(x<<1)+nums[i];
            x%=5;
            ans.push_back((x==0)?true:false);
        }
        return ans;
    }
};