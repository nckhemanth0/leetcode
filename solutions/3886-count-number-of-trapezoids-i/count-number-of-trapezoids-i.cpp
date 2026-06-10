class Solution {
public:

    long long MOD=1e9+7;

    long long mulmod(long long a, long long b) {
        long long res = (a % MOD) * (b % MOD);
        res %= MOD;
        return (long long)res;
    }

    long long nc2(long long n){
        n%=MOD;
        return ((n*(n-1))/2)%MOD;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        long long n=points.size();
        sort(points.begin(),points.end(),[](const vector<int> &a, const vector<int> &b){
            return a[1]<b[1];
        });
        long long prev=points[0][1];
        long long i=0, sum=0, sum_sq=0;
        unordered_set<int> s;
        for(;i<n;i++){
            if(points[i][1]!=prev){
                long long value=nc2(s.size())%MOD;
                sum=(sum+value)%MOD;
                sum_sq=(sum_sq+mulmod(value,value))%MOD;
                prev=points[i][1];
                s.clear();
            }
            s.insert(points[i][0]);
        }
        long long value=nc2(s.size())%MOD;
        sum=(sum+value)%MOD;
        sum_sq=(sum_sq+mulmod(value,value))%MOD;
        s.clear();

        long long sum_sq_total = mulmod(sum, sum);
        long long tmp = (sum_sq_total - sum_sq + MOD) % MOD;
        long long inv2 = (MOD + 1) / 2;
        long long ans = mulmod(tmp, inv2); 
        return ans;
    }
};