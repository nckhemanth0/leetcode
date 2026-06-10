class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        unordered_set<int> set;
        for(auto x: nums){
            set.insert(x);
        }
        while(set.count(original)){
            original*=2;
        }
        return original;
    }
};