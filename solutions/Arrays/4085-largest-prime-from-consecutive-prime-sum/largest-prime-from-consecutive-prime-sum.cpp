class Solution {
public:

    vector<long long> primes;

    void fill(long long n){
        primes[1]=0;
        for(long long i=4;i<=n;i+=2){
            primes[i]=false;
        }
        for(long long i=3;i<=n;i+=2){
            if(primes[i]){
                for(long long j=i*i;j<=n;j+=i){
                    primes[j]=false;
                }
            }
        }        
    }

    int largestPrime(int n) {
        if(n==1){
            return 0;
        }
        primes.resize(n+2,true);
        fill(n);
        int ans=0;
        long long sum=0;
        for(long long i=2;i<=n;i++){
            if(primes[i]){
                sum+=i;
                if(sum>n){
                    break;
                }
                if(primes[sum]){
                    ans=sum;
                }
            }
        }
        return ans;
    }
};