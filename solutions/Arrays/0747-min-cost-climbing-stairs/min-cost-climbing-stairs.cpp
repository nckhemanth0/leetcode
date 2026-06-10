class Solution {
public:

    vector<int> dp;

    int rec(vector<int>& cost,int n){ // cost to reach n;
        if(n==1 || n==0){
            return 0;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n]=min(rec(cost,n-1)+cost[n-1], rec(cost,n-2)+cost[n-2]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.resize(n+1,-1);
        return rec(cost,n);
    }
};