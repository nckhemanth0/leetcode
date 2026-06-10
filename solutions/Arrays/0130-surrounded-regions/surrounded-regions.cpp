class Solution {
public:

    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};

    int m,n;

    void dfs(int r, int c, vector<vector<char>> &board){
        board[r][c]='V';
        for(int k=0;k<4;k++){
            int nr=r+x[k], nc=c+y[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O'){
                dfs(nr,nc,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // O mean not vis and area of concentration
                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O'){
                    dfs(i,j,board);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='V'){
                    board[i][j]='O';
                }
            }
        }
    }
};