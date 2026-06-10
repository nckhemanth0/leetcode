class Solution {
public:
    unordered_map<int,int> mp;
    vector<vector<int>> ans;
    vector<int> result;
    int n;
    void rec(int level){
        if(level==n){
            ans.push_back(result);
        }
        for(auto &[f,s]: mp){
            if(mp[f]){
                result.push_back(f);
                mp[f]--;
                rec(level+1);
                // result.pop_back();
                // mp[f]++;

                // result.push_back(f);
                // mp[f]--;
                // rec(level);
                result.pop_back();
                mp[f]++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(auto x:nums){
            mp[x]++;
        }
        n=nums.size();
        rec(0);
        return ans;
    }
};