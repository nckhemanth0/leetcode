class Solution {
public:
    int mask=0;
    vector<int> ans;
    vector<vector<int>> final_ans;
    int n;
    void rec(int level, vector<int> &nums){
        if(level==n){
            final_ans.push_back(ans);
        }
        for(int i=0;i<n;i++){
            if(!(mask & (1<<i))){
                ans.push_back(nums[i]);
                mask |= (1 << i); // mask=mask^(1<<i);
                rec(level+1,nums);
                ans.pop_back();
                mask &= ~(1 << i); // mask=mask^(1<<i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        rec(0, nums);
        return final_ans;
    }
};