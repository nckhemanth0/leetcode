class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();
        if(n==0){
            return {};
        }
        int start=0,i=1;
        while(i<n){
            if(nums[i]==nums[i-1]+1){
                i++;
            }else{
                if(start==i-1){
                    ans.push_back(to_string(nums[start]));
                }else{
                    ans.push_back(to_string(nums[start])+"->"+to_string(nums[i-1]));
                }
                start=i;
                i++;
            }
        }
        if(start==i-1){
            ans.push_back(to_string(nums[start]));
        }else{
            ans.push_back(to_string(nums[start])+"->"+to_string(nums[i-1]));
        }
        return ans;
    }
};