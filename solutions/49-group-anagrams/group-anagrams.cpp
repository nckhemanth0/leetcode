class Solution {
public:
    // nk
    vector<vector<string>> groupAnagrams(vector<string>& ss) {
        vector<vector<string>> ans;
        map<string,vector<string>> mp;
        for(auto x: ss){
            vector<int> freq(26,0);
            string key="";
            for(auto c: x){
                freq[c-'a']++;
            }
            for(int i=0;i<26;i++){
                // # importatnt for this test case: ["bdddddddddd","bbbbbbbbbbc"]
                key+=(to_string(freq[i]))+"#";
            }
            mp[key].push_back(x);
        }
        for(auto [x,y]: mp){
            ans.push_back(y);
        }
        return ans;
    }

    //tc: nklogk
    vector<vector<string>> groupAnagrams_sort(vector<string>& ss) {
        vector<vector<string>> ans;
        map<string,vector<string>> mp;
        for(auto x: ss){
            string temp=x;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(x);
        }
        for(auto [x,y]: mp){
            ans.push_back(y);
        }
        return ans;
    }
};