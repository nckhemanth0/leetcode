class Solution {
public:
    int n;
    vector<vector<string>> final_ans;
    vector<string> ans;
    int col=0; // tracking in a backtracking path, so far in levels/rows i visited what cols are set
    int diag=0;
    int antidiag=0;

    void rec(int level){
        if(level==n){
            final_ans.push_back(ans);
            return;
        }
        for(int i=0;i<n;i++){
            int d=level-i+n-1;
            int ad=level+i;
            if(!( (col & (1<<i)) || diag & (1<<d) || antidiag & (1<<ad) )){
                ans[level][i]='Q';
                col|=(1<<i);
                diag|=(1<<d);
                antidiag|=(1<<ad);
                rec(level+1);
                ans[level][i]='.';
                col=col&(~(1<<i));
                diag=diag&(~(1<<d));
                antidiag=antidiag&(~(1<<ad));
            }
        }
    }
    vector<vector<string>> solveNQueens(int N) {
        n=N;
        ans.resize(n,string(n,'.'));
        rec(0);
        return final_ans;
    }
};