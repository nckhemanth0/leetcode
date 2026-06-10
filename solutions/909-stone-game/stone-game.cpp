class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int rec(vector<int>& piles, int i, int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MIN;
        // +
        ans=max(ans,piles[i]-rec(piles,i+1,j));
        // -
        ans=max(ans,piles[j]-rec(piles,i,j-1));
        return dp[i][j]=ans;
    }

    bool stoneGame(vector<int>& piles) {
        n=piles.size();
        dp.resize(n+1, vector<int>(n+1,-1));
        return rec(piles,0,n-1)>0 ? true : false;
    }
};