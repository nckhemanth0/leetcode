class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp{1};
        int cnt=1;
        while(cnt<=rowIndex){
            dp.resize(cnt+1);
            dp[0]=dp[cnt]=1;
            for(int j=cnt-1;j>=1;j--){
                dp[j]+=dp[j-1];
            }
            cnt++;
        }
        return dp;
    }
};

// 0123
// dp[i]=dp[i-1]+dp[i]