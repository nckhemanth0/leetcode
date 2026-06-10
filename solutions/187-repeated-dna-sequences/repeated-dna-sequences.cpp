class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        int k=10;
        unordered_map<char,int> mp;
        unordered_map<string,int> ans;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(i>=k){
                mp[s[i]]--;
            }
            if(i>=k-1){
                string x=s.substr(i-10+1,10);
                ans[x]++;
            }
        }
        vector<string> final_ans;
        for(auto x: ans){
            if(x.second>1){
                final_ans.push_back(x.first);
            }
        }
        return final_ans;
    }
};