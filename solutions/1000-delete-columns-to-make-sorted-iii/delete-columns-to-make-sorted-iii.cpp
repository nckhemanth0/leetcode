// form1-knapsack
class Solution1 {
public:
    vector<vector<int>> dp;
    int nr,nc;
    int rec(int level, int prev, vector<string>& strs){
        if(level==nc){
            return 0;
        }
        if(dp[level][prev]!=-1){
            return dp[level][prev];
        }
        int ans=INT_MAX;
        // not delete
        if(prev==nc){
            ans=min(ans,rec(level+1,level,strs));
        }else{
            bool lexi=true;
            for(int r=0;r<nr;r++){
                if(strs[r][prev]>strs[r][level]){
                    lexi=false;
                }
            }
            if(lexi){
                ans=min(ans,rec(level+1,level,strs));
            }
        }
        // delete
        ans=min(ans,rec(level+1,prev,strs)+1);
        return dp[level][prev]=ans;
    }

    int minDeletionSize(vector<string>& strs) {
        nr=strs.size();
        nc=strs[0].size();
        dp.resize(nc+1,vector<int>(nc+1, -1));
        return rec(0,nc,strs);
    }
};

// form2-longest increasing lexi order at index i
class Solution {
public:
    vector<int> dp;
    int nr,nc;
    int rec(int level, vector<string>& strs){
        if(dp[level]!=-1){
            return dp[level];
        }

        int ans=1;
        for(int c=0;c<level;c++){
            bool lexi=true;
            for(int r=0;r<nr;r++){
                if(strs[r][c]>strs[r][level]){
                    lexi=false;
                }
            }
            if(lexi){
                ans=max(ans,rec(c,strs)+1);
            }
        }

        return dp[level]=ans;
    }

    int minDeletionSize(vector<string>& strs) {
        nr=strs.size();
        nc=strs[0].size();
        dp.resize(nc, -1);
        int lis=INT_MIN; // longest increasing lexi order at index i
        for(int i=0;i<nc;i++){
            lis=max(lis,rec(i,strs));
        }
        return nc-lis;
    }
};