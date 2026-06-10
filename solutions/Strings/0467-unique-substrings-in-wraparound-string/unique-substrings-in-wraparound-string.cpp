class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n=s.length();
        vector<int> dp(26,0);
        int len=dp[s[0]-'a']=1;
        for(int i=1;i<n;i++){
            if((s[i]-s[i-1]+26)%26 == 1){
                len++;
            }else{
                len=1;
            }
            dp[s[i]-'a']=max(dp[s[i]-'a'],len);
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=dp[i];
        }
        return ans;
    }
};