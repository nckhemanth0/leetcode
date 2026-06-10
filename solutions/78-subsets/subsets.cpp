class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;
    int n;
    void rec(int level, vector<int>& nums){
        
        if(level==n){
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[level]);
        rec(level+1,nums);
        subset.pop_back();

        rec(level+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        rec(0,nums);
        return ans;
    }
};