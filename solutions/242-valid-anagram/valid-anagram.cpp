class Solution {
public:
    vector<int> mp;
    bool isAnagram(string s, string t) {
        mp.resize(26,0);
        // or can also check case where both sizes not equal, then not anagrams
        for(auto x:s){
            mp[x-'a']++;
        }
        for(auto y:t){
            mp[y-'a']--;
        };
        for(int i=0;i<26;i++){
            if(mp[i]!=0){
                return false;
            }
        }
        return true;
    }
};