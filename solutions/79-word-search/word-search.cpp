class Solution {
public:
    vector<vector<int>> vis;
    int m,n,output=false;

    int x[4] = {0, -1, 0, 1};
    int y[4] = {-1, 0, 1, 0};

    int x8[8]={2,1,-2,-1,-2,-1,2,1};
    int y8[8]={-1,-2,-1,-2,1,2,1,2};

    bool check(int nr, int nc){
        return nr >= 0 && nc >= 0 && nr < n && nc < m;
    }

    void rec(vector<vector<char>>& board, string word,int r,int c,string ans){
        if(ans.size()>word.size()){ // pruning method i thought
            return;
        }
        if(ans==word){
            output=true;
            return;
        }
        for(int i=0;i<4;i++){
            int nr=x[i]+r;
            int nc=y[i]+c;
            // board[nr][nc]==word[ans.size()] => pruning method i thought
            if(check(nr,nc) && !vis[nr][nc] && board[nr][nc]==word[ans.size()]){
                vis[nr][nc]=1;
                rec(board,word,nr,nc,ans+board[nr][nc]);
                vis[nr][nc]=0;
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        n=board.size(),m=board[0].size();
        vis.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    string ans=string()+board[i][j];
                    rec(board,word,i,j,ans);
                    vis[i][j]=0;
                }
            }
        }
        return output;
    }
};