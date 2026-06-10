class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int rec(vector<int>& piles, int level, int m){
        if(level==n){
            return 0;
        }
        if(dp[level][m]!=-1){
            return dp[level][m];
        }
        int ans=INT_MIN;
        int sumTaken=0;
        for(int i=0;i<2*m && level+i<n;i++){
            int index=level+i;
            sumTaken+=piles[index];
            ans=max(ans,sumTaken-rec(piles,index+1,max(m,i+1)));
        }
        return dp[level][m]=ans;
    }

    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return (rec(piles,0,1)+accumulate(piles.begin(),piles.end(),0))/2;
    }
};