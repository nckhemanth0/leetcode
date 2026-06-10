class Solution {
public:

    bool checkPrime(string num){
        if(num=="1"){
            return false;
        }
        int x=stoi(num);
        int cnt=0;
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                cnt++;
            }
        }
        return cnt==0;
    }

    bool completePrime(int num) {
        string v=to_string(num);
        int n=v.size();
        for(int len=1,j=n-1;len<=n && j>=0;len++,j--){
            if(!checkPrime(v.substr(0,len)) || !checkPrime(v.substr(j,len))){
                return false;
            }
        }
        return true;
    }
};