class Solution {
public:

    int getSubstringsWithCenter(string &s, int l, int r){
        int ans=0;
        while(l>=0 && r<s.length() && l<=r && s[l]==s[r]){
            ans++;
            l--;
            r++;
        }
        return ans;
    }

    int countSubstrings(string &s) {
        // dp[i][j]=[i,j] substrig is a strict palindrome
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            
            // odd case
            int l=i,r=i;
            ans+=getSubstringsWithCenter(s,l,r);

            // even case
            l=i,r=i+1;
            ans+=getSubstringsWithCenter(s,l,r);
        }
        return ans;
    }

    // ======== ======== ======== ======== ======== ======== ======== ======== ======== ======== ======== ======== ======== ========

    vector<vector<int>> dp;
    int rec(string &s, int i, int j){ // this &s is very important
        if(i>=j){
            return dp[i][j]=1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]==s[j]){
            ans=rec(s,i+1,j-1);
        }else{
            ans=0;
        }
        rec(s,i+1,j);
        rec(s,i,j-1);
        return dp[i][j]=ans;
    }

    int countSubstrings__DP(string s) {
        // dp[i][j]=[i,j] substrig is a strict palindrome
        int n=s.length();
        dp.resize(n,vector<int>(n,-1));
        rec(s,0,n-1);
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]==1){
                    sum++;
                }
            }
        }
        return sum;
    }
};