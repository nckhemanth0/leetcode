class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1=lower_bound(nums.begin(), nums.end(),target);
        auto it2=upper_bound(nums.begin(), nums.end(),target);
        auto it=nums.begin();
        if(it1==it2){
            return {-1,-1};
        }else{
            return {(int)(it1-nums.begin()), (int)(it2-nums.begin()-1)};
        }
    }
};