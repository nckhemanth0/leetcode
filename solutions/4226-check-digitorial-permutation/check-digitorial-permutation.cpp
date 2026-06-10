class Solution {
public:

    bool isDigitorialPermutation(int n) {
        vector<long long> fact(10,0);
        for(int i=0;i<=9;i++){
            if(i==0){
                fact[0]=1;
            }else{
                fact[i]=fact[i-1]*i;
            }
        }
        string x=to_string(n);
        sort(x.begin(),x.end());
        long long ans=0;
        for(auto c: x){
            long long v=c-'0';
            ans+=fact[v];
        }
        do{
            if(!x.empty() && x[0]=='0'){
                continue;
            }
            if(ans==stoll(x)){
                return true;
            }
        }while(next_permutation(x.begin(),x.end()));
        return false;
    }
};