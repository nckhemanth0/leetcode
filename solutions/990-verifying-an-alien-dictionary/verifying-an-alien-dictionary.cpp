class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n=words.size();
        unordered_map<char,int> mp;
        int ind=0;
        for(auto x: order){
            mp[x]=ind++;
        }
        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            
            int j=0;

            while(j<s1.length() && j<s2.length()){
                if(mp[s1[j]]>mp[s2[j]]){
                    return false;
                }
                else if(mp[s1[j]]<mp[s2[j]]){
                    break;
                }
                j++;
            }

            if(j==s2.length() && s1.length()>s2.length()){
                return false;
            }

        }
        return true;
    }

    // ================

    bool isAlienSorted_compare_function(vector<string>& words, string order) {
        int n=words.size();
        unordered_map<char,int> mp;
        int ind=0;
        for(auto x: order){
            mp[x]=ind++;
        }
        auto compare=[&mp](const string &a, const string &b){
            for(int i=0;i<min(a.length(),b.length());i++){
                if(mp[a[i]]>mp[b[i]]){
                    return false;
                }else if(mp[a[i]]<mp[b[i]]){
                    return true;
                }
            }
            return a.length()<b.length();
        };
        return is_sorted(words.begin(),words.end(),compare);
    }
};