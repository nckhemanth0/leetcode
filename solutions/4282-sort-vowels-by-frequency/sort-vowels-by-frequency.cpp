class Solution {
public:
    bool isVowel(char &c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    string sortVowels(string s) {
        char vo[5]={'a','e','i','o','u'};
        int n=s.size();
        vector<pair<int,pair<int,int>>> v;
        unordered_map<int,int> mp;
        unordered_map<int,int> first;
        
        for(int i=0;i<n;i++){
            if(!isVowel(s[i])){
                continue;
            }
            mp[s[i]-'a']++;
            if(!first.count(s[i]-'a')){
                first[s[i]-'a']=i;
            }
        }
        for(auto x: mp){
            v.push_back({-x.second,{first[x.first],x.first}});
        }
        sort(v.begin(),v.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                s[i]=v[j].second.second+'a';
                v[j].first++;
                if(v[j].first==0){
                    j++;
                }
            }
        }
        return s;
    }
};