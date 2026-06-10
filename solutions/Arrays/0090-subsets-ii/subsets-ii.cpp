class Solution {
public:
    vector<vector<int>> final_ans;
    vector<int> subset;
    int n;
    void rec(int level, vector<int>& nums){
        if(level==n){
            final_ans.push_back(subset);
            return;
        }

        subset.push_back(nums[level]);
        rec(level+1,nums);
        subset.pop_back();

        int cur=nums[level];
        while(level<n && nums[level]==cur){
            level++;
        }
        rec(level,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        rec(0,nums);
        return final_ans;
    }
};