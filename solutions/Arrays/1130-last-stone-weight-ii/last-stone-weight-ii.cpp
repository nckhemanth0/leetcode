class Solution {
public:
    int n;
    vector<vector<int>> dp;
    /*
        let say array be [a,b,c,d]
        answer = (a+b)-(c+d) OR a-(b+c+d) Or (d+b)-(a+c) and so on.. 
        any combination could be possible
        notice that in general I can say that answer = S1-S2 where S1 is sum of some of the numbers and S2 is sum of rest of numbers
        also note that S1+S2 = SUM (sum of all numbers)
        S1 >= S2 beacuse negative answer is not possible
        now we have to minimise answer = SUM - 2*S2 (Just substituting S1 by SUM-S2)
        To minimise answer S2 has to be maximum
        Now, max value of S2 is SUM/2 (bigger than this and answer would be negative which is not possible)
        
        So the question reduces to find closest sum (sum of numbers) to (SUM/2)
        now this could be understood as subset sum problem or 0/1 knapsack problem
    */
    int rec(vector<int>& stones, int i, int sum) {
        if (i == n || sum == 0) return 0;  // Base case: No more elements or sum reaches 0
        if (dp[i][sum] != -1) return dp[i][sum];
        int ans = rec(stones, i + 1, sum);  // Not including the current stone
        if (stones[i] <= sum) {  
            // Including the current stone
            ans = max(ans, stones[i] + rec(stones, i + 1, sum - stones[i]));
        }
        return dp[i][sum] = ans;
    }

    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        int total = accumulate(stones.begin(), stones.end(), 0);
        int sum = total / 2;
        dp.assign(n, vector<int>(sum + 1, -1));

        int maxS2 = rec(stones, 0, sum);  // Max sum close to SUM/2
        return total - 2 * maxS2;  // Minimized difference
    }

    // ======= ======= ======= ======= ======= ======= ======= ======= ======= ======= ======= =======

    unordered_map<int,unordered_map<int,int>> dp1;
    /*
        dp[level][sum] => for state till level having sum of stored state till now, 
        what is min answer we can make with any combination of future levels

        Here we have to travel entire path and in the end we decide on answer and propagate backwards
    */
    int rec1(vector<int>& stones, int level, int sum){
        if(level==n){
            if(sum>=0){
                return sum;
            }else{
                return INT_MAX;
            }
        }
        if(dp1.count(level) && dp1[level].count(sum)){
            return dp1[level][sum];
        }
        int ans=INT_MAX;
        // - case
        ans=min(ans,rec1(stones,level+1,sum-stones[level]));
        // + case
        ans=min(ans,rec1(stones,level+1,sum+stones[level]));
        return dp1[level][sum]=ans;
    }

    int lastStoneWeightII__1(vector<int>& stones) {
        n=stones.size();
        return rec1(stones,0,0);
    }
};