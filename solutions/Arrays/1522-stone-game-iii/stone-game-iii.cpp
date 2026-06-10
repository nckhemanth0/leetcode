class Solution {
public:

    int n;
    vector<int> dp;
    // REC: DP: diff b/w current and other player if played optimally
    int rec(vector<int>& stoneValue, int level){
        if(level==n){
            return 0;
        }
        if(dp[level]!=-1e5){
            return dp[level];
        }
        int diff=INT_MIN;
        int pickSum=0;
        for(int i=0;i<3;i++){
            if(level+i<n){
                pickSum+=stoneValue[level+i];
                diff=max(diff,pickSum-rec(stoneValue,level+i+1));
            }
        }
        return dp[level]=diff;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int sum=0;
        n=stoneValue.size();
        suffixSum.resize(n+1,0);
        dp.resize(n+1,-1e5);
        for(int i=n-1;i>=0;i--){
            sum+=stoneValue[i];
            suffixSum[i]=sum;
        }
        int diff=rec(stoneValue,0);
        if(diff>0){
            return "Alice";
        }else if(diff==0){
            return "Tie";
        }else{
            return "Bob";
        }
    }

    // ========== ========== ========== ========== ========== ========== ========== ========== ========== 

    int n1;
    vector<int> suffixSum; // inclusing current index
    vector<int> dp1;
    // REC: DP: max sum that player playing at 'level' can get
    int rec1(vector<int>& stoneValue, int level){
        if(level==n1){
            return 0;
        }
        if(dp1[level]!=-1e5){
            return dp1[level];
        }
        int currentPlayerMaxSum=INT_MIN;
        int pickSum=0;
        for(int i=0;i<3;i++){
            if(level+i<n1){
                pickSum+=stoneValue[level+i];
                int otherPlayerMaxSum=rec1(stoneValue,level+i+1);
                currentPlayerMaxSum=max(currentPlayerMaxSum,pickSum+suffixSum[level+i+1]-otherPlayerMaxSum);
            }
        }
        return dp1[level]=currentPlayerMaxSum;
    }

    string stoneGameIII__BIG(vector<int>& stoneValue) {
        int sum=0;
        n1=stoneValue.size();
        suffixSum.resize(n1+1,0);
        dp1.resize(n1+1,-1e5);
        for(int i=n1-1;i>=0;i--){
            sum+=stoneValue[i];
            suffixSum[i]=sum;
        }
        int alice_sum=rec1(stoneValue,0);
        int bob_sum=sum-alice_sum;
        if(alice_sum>bob_sum){
            return "Alice";
        }else if(alice_sum==bob_sum){
            return "Tie";
        }else{
            return "Bob";
        }
    }
};