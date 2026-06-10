class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n=s.length();
        int tail=0, head=-1,cnt=0,ans=0;
        unordered_map<char,int> mp;
        while(tail<n){
            // if next char is seen
            // if next char not seen and cnt<k
            while(head+1<n && (mp[s[head+1]]!=0 || cnt<k)){
                head++;
                mp[s[head]]++;
                if(mp[s[head]]==1){
                    cnt++;
                }
            }
            ans=max(ans,head-tail+1);
            mp[s[tail]]--;
            if(mp[s[tail]]==0){
                cnt--;
            }
            tail++;
        }
        return ans;
    }
};