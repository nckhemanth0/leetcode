class Solution {
public:
    vector<int> dp;
    vector<int> countBits(int n) {
        dp.resize(n+1,0);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                dp[i]=dp[i/2];
            }else{
                dp[i]=dp[i/2]+1;
            }
        }
        return dp;
    }
};