class Solution {
public:
    int minOperations(string s) {
        int cnt=0,ans=s.size()/2;
        // 10101
        for(int i=0;i<s.size();i++){
            if(i%2==0 && s[i]=='0'){
                cnt++;
            }else if(i%2==1 && s[i]=='1'){
                cnt++;
            }
        }
        ans=min(ans,cnt);
        cnt=0;
        // 0101
        for(int i=0;i<s.size();i++){
            if(i%2==0 && s[i]=='1'){
                cnt++;
            }else if(i%2==1 && s[i]=='0'){
                cnt++;
            }
        }
        ans=min(ans,cnt);
        return ans;
    }
};