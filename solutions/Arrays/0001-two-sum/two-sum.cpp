class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 1. sort, 2 pointer - nlogn
        // 2. hashmap - n
        unordered_map<int,int> mp;       
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(mp.find(target-x)!=mp.end()){
                return {i,mp[target-x]};
            }
            mp[x]=i;
        }
        return {};
    }
    vector<int> twoSum_1(vector<int>& nums, int target) {
        // 1. sort, 2 pointer - nlogn
        // 2. hashmap - n
        map<int,int> mp;       
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(mp[target-x]){
                return {i,mp[target-x]-1};
            }
            mp[x]=i+1;
        }
        return {};
    }
    vector<int> twoSum_2(vector<int>& nums, int target) {
        // 1. sort, 2 pointer - nlogn
        // 2. hashmap - n
        map<int,int> mp;       
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(mp.find(target-x)!=mp.end() && mp[target-x]!=i){
                return {i,mp[target-x]};
            }
            mp[x]=i;
        }
        return {};
    }
};