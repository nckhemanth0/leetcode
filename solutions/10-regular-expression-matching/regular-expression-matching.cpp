class Solution {
public:
    int ns, np;
    int dp[21][21];
    bool rec(int i, int j, string s, string p){
        if(j==np && i==ns){
            return true;
        }
        if(j==np){
            return false;
        }
        if(i==ns){
            while (j < np) {
                if (j + 1 < np && p[j+1] == '*') {
                    j += 2; 
                } else {
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if (j + 1 < np && p[j+1] == '*'){
            if (p[j] != '.') {
                int endCharIndex=i;
                int start=s[i];
                if(s[i] == p[j]){
                    while(endCharIndex<ns && s[endCharIndex]==start){
                        endCharIndex++;
                    }
                    for(int k=i;k<endCharIndex;k++){
                        if(rec(k+1,j+2,s,p)){
                            return dp[i][j] = true;
                        }
                    }
                }
                return dp[i][j] = rec(i,j+2,s,p);
            } else {
                int endCharIndex=ns;
                for(int k=i;k<endCharIndex;k++){
                    if(rec(k+1,j+2,s,p)){
                        return dp[i][j] = true;
                    }
                }
                return dp[i][j] = rec(i,j+2,s,p);
            }
        } else {
            if (p[j] != '.'){
                return dp[i][j] = (s[i] == p[j] ? rec(i+1,j+1,s,p) : false);
            } else {
                return dp[i][j] = rec(i+1,j+1,s,p);
            }
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        ns = s.size();
        np = p.size();
        memset(dp, -1, sizeof(dp));
        return rec(0,0,s,p);
    }
};