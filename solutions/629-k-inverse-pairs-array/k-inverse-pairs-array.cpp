class Solution {
public:
    int mod=1e9+7;
    int kInversePairs(int n, int k) {
        vector<long long> dp(k+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            vector<long long> pref(k+2);
            for(int j=0;j<=k;j++){
                pref[j+1]=(pref[j]%mod+dp[j]%mod)%mod;
                int len=j-i+1;
                dp[j]=(pref[j+1]-(len>0?pref[len]:0)+mod)%mod;
            }
        }
        return dp[k];
    }
};

/*
    f(n,k)=f(n−1,k)+f(n−1,k−1)+f(n−1,k−2)+⋯+f(n−1,k−n+1)
*/


/*
    class Solution {
    public:
        int kInversePairs(int n, int k) {
            const int MOD = 1000000007;
            vector<int> dp(k + 1, 0), ndp(k + 1, 0), prefix(k + 1, 0);
            dp[0] = 1;

            for(int i = 1; i <= n; i++) {
                prefix[0] = dp[0];
                for(int j = 1; j <= k; j++)
                    prefix[j] = (prefix[j - 1] + dp[j]) % MOD;

                for(int j = 0; j <= k; j++) {
                    int l = j - (i - 1);
                    long long val = prefix[j];
                    if(l > 0) val = (val - prefix[l - 1]) % MOD;
                    if(val < 0) val += MOD;
                    ndp[j] = (int)val;
                }
                dp.swap(ndp);
                fill(ndp.begin(), ndp.end(), 0);
            }
            return dp[k];
        }
    };
*/