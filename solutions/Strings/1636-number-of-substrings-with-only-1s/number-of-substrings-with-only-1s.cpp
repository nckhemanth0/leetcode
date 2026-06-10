class Solution {
public:
    const int MOD=1e9+7;
    int numSub(string s) {
        long long left=0,ans=0,cnt0=0;
        for(int right=0;right<s.length();right++){
            if(s[right]=='0'){
                cnt0++;
            }
            while(cnt0>0){
                if(s[left]=='0'){
                    cnt0--;
                }
                left++;
            }
            if(cnt0==0){
                ans=(ans%MOD+(right-left+1)%MOD)%MOD;
            }
        }
        return ans;
    }
};