class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int> mp;
        int head=-1,tail=0,ans=0,n=s.length();
        while(tail<n){
            while((head+1<n) && (mp[s[head+1]]==0)){
                head++;
                mp[s[head]]++;
            }
            ans=max(ans,head-tail+1);
            mp[s[tail]]--;
            tail++;
        }
        return ans;
    }
};