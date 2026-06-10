class Solution {
public:
    int magicalString(int n) {
        string x="122";
        int ans=1;
        int cur=1;
        int i=2;
        int j=3;
        while(j<n){
            if(x[i]=='1'){
                x+=cur+'0';
                j++;
            }else{
                char c=cur+'0';
                x+=c;
                x+=c;
                j+=2;
                ans+=2;
            }
            cur=3-(x[j-1]-'0');
            i++;
        }
        ans=0;
        for(int i=0;i<n;i++){
            if(x[i]=='1'){
                ans++;
            }
        }
        return ans;
    }
};