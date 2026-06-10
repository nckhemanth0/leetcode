class Solution {
public:
    int maxFreqSum(string s) {
        int n=s.length();
        int c1=0,c2=0;
        vector<int> cnt(26,0);
        for(auto x: s){
            cnt[x-'a']++;
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
                c1=max(c1,cnt[x-'a']);
            }else{
                c2=max(c2,cnt[x-'a']);
            }
        }
        return c1+c2;
    }
};