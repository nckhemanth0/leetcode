class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        for(auto x: trips){
            mp[x[1]]+=x[0];
            mp[x[2]]-=x[0];
        }
        int cap=0;
        for(auto x: mp){
            cap+=x.second;
            if(cap>capacity){
                return false;
            }
        }
        return true;
    }
};