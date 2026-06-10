class Solution {
public:
    using ll=long long;
    ll minCost(string s, vector<int>& cost) {
        unordered_map<char,ll> mp;
        ll sum=0;
        for(int i=0;i<cost.size();i++){
            mp[s[i]]+=cost[i];
            sum+=cost[i];
        }
        ll ans=LLONG_MAX;
        for(char i='a';i<='z';i++){
            ans=min(ans,sum-mp[i]);
        }
        return ans;
    }
};