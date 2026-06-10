class Solution {
public:
    int MOD=1e9+7;

    long long binpow(long long a, long long b){
        int res=1;
        a%=MOD;
        while(b>0){
            if(b&1){
                res=(res*a)%MOD;
            }
            a=((a%MOD)*(a%MOD))%MOD;
            b=b>>1;
        }
        return res;
    }

    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(),ranges.end());
        int rightend=-1; // instead of pushing into vector, i just track back's end 
        int cnt=0;
        for(int i=0;i<ranges.size();i++){
            if(rightend<ranges[i][0]){
                cnt++;
            }
            rightend=max(rightend,ranges[i][1]);
        }
        return binpow(2,cnt);
    }
};