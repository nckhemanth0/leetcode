class Solution {
public:
    long long numberOfWays(string s) {
        int suffix0=0, suffix1=0;
        long long n=s.size(), ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                suffix0++;
            }else{
                suffix1++;
            }
        }
        int prefix0=0,prefix1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                suffix1--;
            }else{
                suffix0--;
            }
            long long x1=(s[i]=='1'?prefix0:prefix1);
            long long x2=(s[i]=='1'?suffix0:suffix1);
            ans=ans+(x1*x2);
            if(s[i]=='1'){
                prefix1++;
            }else{
                prefix0++;
            }
        }
        return ans;
    }

    // ====== ====== ====== ====== ====== ====== ======

    long long numberOfWays__1st_approach(string s) {
        unordered_map<char,int> prefix,suffix;
        long long n=s.size(), ans=0;
        for(int i=n-1;i>=1;i--){
            suffix[s[i]]++;
        }
        prefix[s[0]]++;
        for(int i=1;i<=n-2;i++){
            suffix[s[i]]--;
            long long x1=prefix['1'-s[i]+'0'];
            long long x2=suffix['1'-s[i]+'0'];
            ans=ans+(x1*x2);
            prefix[s[i]]++;
        }
        return ans;
    }
};