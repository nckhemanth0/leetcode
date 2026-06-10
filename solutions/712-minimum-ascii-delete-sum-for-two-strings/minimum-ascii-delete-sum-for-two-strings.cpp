/*
        OTHER METHOD: 
            dp[i][j] = maximum ASCII sum of common subsequence
            ans = total_ascii - 2 * dp[n][m]
*/

class Solution {
public:
    vector<int> pre1,pre2;
    int n1,n2;
    vector<vector<int>> dp;
    int rec(int i, int j, string &s1, string &s2){
        if(i>=n1 && j>=n2){
            return 0;
        }
        if(i>=n1){
            // other way: can do return dp[i][j]=rec(i,j+1,s1,s2)+s2[j];
            return pre2[j];
        }
        if(j>=n2){
            // other way: can do return dp[i][j]=rec(i+1,j,s1,s2)+s1[i];
            return pre1[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        if(s1[i]==s2[j]){
            ans=min(ans,rec(i+1,j+1,s1,s2));
        }else{
            ans=min({ans,rec(i+1,j,s1,s2)+s1[i],rec(i,j+1,s1,s2)+s2[j]});
        }
        return dp[i][j]=ans;
    }

    void compute(vector<int> &pre, string &s){
        int n=s.size();
        pre.resize(n+1,0);
        for(int i=n-1;i>=0;i--){
            pre[i]=pre[i+1]+s[i];
        }
    }    

    int minimumDeleteSum(string s1, string s2) {
        n1=s1.size(),n2=s2.size();
        compute(pre1,s1);
        compute(pre2,s2);
        dp.resize(n1+1,vector<int>(n2+1,-1));
        return rec(0,0,s1,s2);
    }
};