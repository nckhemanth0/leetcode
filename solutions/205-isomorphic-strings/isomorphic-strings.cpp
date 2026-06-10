class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        if(n!=t.length()) return false;
        unordered_map<char,char> mp;
        unordered_set<char> set;
        for(int i=0;i<n;i++){
            if(!mp.count(s[i])){
                if(set.count(t[i])){
                    return false;
                }
                mp[s[i]]=t[i];
                set.insert(t[i]);
            }else if(mp[s[i]]!=t[i]){
                return false;
            }
        }
        return true;
    }
};