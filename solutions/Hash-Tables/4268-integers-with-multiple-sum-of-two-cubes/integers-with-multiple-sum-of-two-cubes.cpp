class Solution {
public:
    using ll=long long;
    vector<int> findGoodIntegers(int n) {
        unordered_map<ll,set<string>> mp;
        int hi=cbrt(n);
        for(ll i=1;i<=hi;i++){
            if(i>=n){
                break;
            }
            for(ll j=i;j<=hi;j++){
                if(j>=n){
                    break;
                }
                ll key=pow(i,3)+pow(j,3);
                if(key>n){
                    break;
                }
                string val=to_string(i)+"#"+to_string(j);
                mp[key].insert(val);
            }
        }
        vector<int> ans;
        for(auto x: mp){
            if(x.first<=n && x.second.size()>=2){
                ans.push_back(x.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};