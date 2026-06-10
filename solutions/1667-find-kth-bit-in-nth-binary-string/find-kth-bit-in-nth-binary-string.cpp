class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        while(s.size()<k){
            string ns=string(s);
            for(int i=0;i<ns.size();i++){
                if(ns[i]=='1'){
                    ns[i]='0';
                }else{
                    ns[i]='1';
                }
            }
            reverse(ns.begin(),ns.end());
            s=s+'1'+ns;
        }
        return s[k-1];
    }
};