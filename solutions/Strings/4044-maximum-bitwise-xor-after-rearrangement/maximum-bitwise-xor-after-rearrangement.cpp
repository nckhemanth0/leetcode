class Solution {
public:
    string maximumXor(string s, string t) {
        unordered_map<char,int> mp;
        for(auto x: t){
            mp[x]++;
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                if(mp['1']){
                    ans+='1';
                    mp['1']--;
                }else{
                    ans+='0';
                    mp['0']--;
                }
            }else{
                if(mp['0']){
                    ans+='0';
                    mp['0']--;
                }else{
                    ans+='1';
                    mp['1']--;
                }
            }
        }
        string final_ans="";
        for(int i=0;i<s.length();i++){
            final_ans.push_back(((s[i]-'0')^(ans[i]-'0'))+'0');
        }
        return final_ans;
    }
};