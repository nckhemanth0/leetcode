class Solution__Direct {
public:
    int mod=1e9+7;

    int numOfWays(int n) {
        // p121: 121, 131, 212, 232, 313, 323 => each has next 5 (212, 213, 232, 312, 313)
        // p123: 123, 132, 213, 231, 312, 321 => each has next 4 (212, 231, 312, 232)
        long long p121=6, p123=6, np121, np123;
        for(int i=1;i<n;i++){
            np121=p121*3+p123*2;
            np123=p121*2+p123*2;
            p121=np121%mod;
            p123=np123%mod;
        }
        return (p123+p121)%mod;
    }
};

class Solution {
public:
    int mod=1e9+7;
    int dp[5001][4][4][4]; // 0,1,2,3 => 4 possibilities (3 being not possible case)

    int rec(int i, int p1, int p2, int p3){
        if(i==-1){
            return 1;
        }
        if(dp[i][p1][p2][p3]!=-1){
            return dp[i][p1][p2][p3];
        }

        long long ans=0;
        for(int c1=0;c1<3;c1++){
            for(int c2=0;c2<3;c2++){
                for(int c3=0;c3<3;c3++){
                    if(c1!=c2 && c2!=c3 && c1!=p1 && c2!=p2 && c3!=p3){
                        ans = ((ans%mod) + (rec(i-1,c1,c2,c3)%mod))%mod;
                    }
                }
            }
        }
        return dp[i][p1][p2][p3]=(int)ans;
    }

    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n-1,3,3,3);
    }
};

class Solution__possible_states {
public:
        int mod=1e9+7;
    int dp[5001][12];
    string states[12]={"RYG","RGY","RYR","RGR","YRG","YGR","YGY","YRY","GRY","GYR","GRG","GYG"};

    int rec(int n,int prev){
        if(n==0){
            return 1;
        }
        int &res=dp[n][prev];
        if(res!=-1){
            return res;
        }
        long long ans=0;
        for(int cur=0;cur<12;cur++){
            if(states[cur][0]==states[prev][0] || states[cur][1]==states[prev][1] || states[cur][2]==states[prev][2]){
                continue;
            }
            ans=(ans+rec(n-1,cur))%mod;
        }
        return res=(int)ans;
    }

    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        long long ans=0;
        for(int i=0;i<12;i++){
            ans=(ans+rec(n-1,i))%mod;
        }
        return (int)ans;
    }
};
