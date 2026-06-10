class Solution {
    List<String> ans=new ArrayList<String>();
    StringBuilder s=new StringBuilder();
    public void rec(int c1,int c2){
        if(c1==0 && c2==0){
            ans.add(s.toString());
            return;
        }
        if(c1>0){
            s.append('(');
            rec(c1-1,c2);
            s.deleteCharAt(s.length()-1);
        }
        if(c1<c2){
            s.append(')');
            rec(c1,c2-1);
            s.deleteCharAt(s.length()-1);
        }
    }

    public List<String> generateParenthesis(int n) {
        int c1=n;
        int c2=n;
        rec(c1,c2);
        return ans;
    }
}



// below here s+'(' will not update s
/*
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();

        dfs(0, 0, "", n, res);

        return res;        
    }

    private void dfs(int openP, int closeP, String s, int n, List<String> res) {
        if (openP == closeP && openP + closeP == n * 2) {
            res.add(s);
            return;
        }

        if (openP < n) {
            dfs(openP + 1, closeP, s + "(", n, res);
        }

        if (closeP < openP) {
            dfs(openP, closeP + 1, s + ")", n, res);
        }
    }    
}
*/