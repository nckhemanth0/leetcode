class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for(auto x: intervals){
            mp[x[0]]++;
            mp[x[1]]-=1;
        }
        vector<vector<int>> ans;
        int cnt=0,l=0;
        for(auto x: mp){
            if(cnt==0){
                l=x.first;
            }
            cnt+=x.second;
            if(cnt==0){
                ans.push_back({l,x.first});
            }
        }
        return ans;
    }
};