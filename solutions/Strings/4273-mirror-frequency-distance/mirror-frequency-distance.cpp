class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int> mp;
        for(auto x:s){
            mp[x]++;
        }
        int ans=0;
        set<char> set;
        for(auto x: mp){
            if(x.second==0){
                continue;
            }
            char c=x.first;
            bool f=isdigit(c);
            char m;
            if(f){
                int temp=(9-(c-'0'));
                m=temp+'0';
            }else{
                int temp='z'-c;
                m='a'+temp;
            }
            if(!set.count(c) || !set.count(m)){
                ans+=abs((mp.count(c)?mp[c]:0)-(mp.count(m)?mp[m]:0));
            }
            set.insert(c);
            set.insert(m);
            
        }
        return ans;
    }
};