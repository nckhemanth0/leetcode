class Solution {
public:

    int n1;
    const int MAXI1=1e3+1;

    /*

        // holding => MAXI-nothing, 1-hold stock
        long long rec__MLE(int level, int holding, int k, vector<int>& prices, vector<vector<vector<long long>>> &dp){
            if(k<0){
                return LLONG_MIN;
            }
            if(level==n1){
                if(k>=0){
                    return 0;
                }
            }
            if(dp[level][holding][k]!=-1){
                return dp[level][holding][k];
            }
            long long ans=0;
            if(holding==MAXI1){ // have nothing
                ans=max(ans,rec__MLE(level+1,MAXI1,k,prices,dp)); // skip
                ans=max(ans,rec__MLE(level+1,level,k,prices,dp)); // buy
            }else{ // have stock
                ans=max(ans,rec__MLE(level+1,holding,k,prices,dp)); // skip
                ans=max(ans,rec__MLE(level+1,MAXI1,k-1,prices,dp)+abs(prices[holding]-prices[level])); // sell
            }
            return dp[level][holding][k]=ans;
        }

    */

    /*
        state:
            0 - free
            1 - buy
            2 - sell
    */

    int n;

    long long rec(int level, int state, int k, vector<int>& prices, vector<vector<vector<long long>>> &dp){
        if(k<0){
            return -1e9;
        }
        if(level==n){
            if(state==0){
                return 0;
            }
            return -1e9;
        }
        if(dp[level][state][k]!=-1){
            return dp[level][state][k];
        }
        long long ans=rec(level+1,state,k,prices,dp);
        if(state==0){
            ans=max(ans,-prices[level]+rec(level+1,1,k-1,prices,dp));
            ans=max(ans,prices[level]+rec(level+1,2,k-1,prices,dp));
        }else if(state==1){
            ans=max(ans,prices[level]+rec(level+1,0,k,prices,dp));
        }else if(state==2){
            ans=max(ans,-prices[level]+rec(level+1,0,k,prices,dp));
        }
        return dp[level][state][k]=ans;
    }


    long long maximumProfit(vector<int>& prices, int k) {
        vector<vector<vector<long long>>> dp;
        // n1=prices.size();
        n=prices.size();
        dp.resize(n,vector<vector<long long>>(3,vector<long long>(k+1,-1)));
        return rec(0,0,k,prices,dp);
    }
};