class Solution {
public:
    long long sumAndMultiply(int n) {
        
        long long sum=0;
        long long x=0;
        while(n){
            if(n%10){
                x=x*10+n%10;
            }
            sum+=(n%10);
            n/=10;
        }
        long long y=0;
        while(x){
            y=y*10+x%10;
            x/=10;
        }
        return sum*y;
    }
};