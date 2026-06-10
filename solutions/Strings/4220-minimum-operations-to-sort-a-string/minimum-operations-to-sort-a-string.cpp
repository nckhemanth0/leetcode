class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string sorteds=string(s);
        sort(sorteds.begin(),sorteds.end());
        if(n==1 || s==sorteds){
            return 0;
        }else if(n==2){
            return s[0]<=s[1]?0:-1;
        }
        char mini='z';
        char maxi='a';
    
        vector<int> v(26,0);
        for(auto x: s){
            v[x-'a']++;
            mini=min(mini,x);
            maxi=max(maxi,x);
        }
        if((mini==s[0] && v[s[0]-'a']==1) || (maxi==s[n-1] && v[s[n-1]-'a']==1)){
            return 1;
        }else if(mini==s[0] || maxi==s[n-1]){
            return 1;
        }else if((mini==s[n-1] && v[s[n-1]-'a']==1) && (maxi==s[0] && v[s[0]-'a']==1)){
            return 3;
        }else{
            return 2;
        }
        return -1;
    }
};