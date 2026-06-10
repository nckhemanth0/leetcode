class Solution {
    Boolean dp[][];
    Boolean rec(int i, int j, String s){
        if(i>=j){
            return true;
        }
        if(dp[i][j]!=null){
            return dp[i][j];
        }
        if(s.charAt(i)==s.charAt(j)){
            return dp[i][j]=rec(i+1,j-1,s);
        }
        return dp[i][j]=false;
    }

    public String longestPalindrome(String s) {
        int n=s.length();
        int[] ends={0,0};
        int ans=Integer.MIN_VALUE;
        dp=new Boolean[n+1][n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(rec(i,j,s) && ans<(j-i+1)){
                    ends[0]=i;
                    ends[1]=j;
                    ans=j-i+1;
                }
            }
        }
        return s.substring(ends[0],ends[1]+1);
    }
}