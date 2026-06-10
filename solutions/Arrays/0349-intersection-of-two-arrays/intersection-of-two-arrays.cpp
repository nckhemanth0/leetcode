class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(auto x: nums1){
            mp[x]++;
        }
        unordered_set<int> set;
        for(auto x: nums2){
            if(mp[x]){
                set.insert(x);
            }
        }
        return vector<int>(set.begin(),set.end());
    }
};