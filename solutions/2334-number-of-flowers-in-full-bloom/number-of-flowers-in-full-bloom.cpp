class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<pair<int,int>> events;
        for(auto x: flowers){
            events.push_back({x[0],1});
            events.push_back({x[1]+1,-1});
        }
        map<int,int> mp;
        sort(events.begin(),events.end());
        int active=0;
        for(auto event: events){
            active+=event.second;
            mp[event.first]=active;
        }
        vector<int> ans;
        for(auto x: people){
            auto it = mp.upper_bound(x);
            if(it==mp.begin()){
                ans.push_back(0);
            }else{
                auto prevIt=prev(it);
                ans.push_back(prevIt->second);
            }
        }
        return ans;
    }
};