class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    if(i>=1 && board[i-1][j]=='X'){
                        continue;
                    }
                    if(j>=1 && board[i][j-1]=='X'){
                        continue;
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};


/*

    class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    int k=i+1;
                    while(k<m && board[k][j]=='X'){
                        board[k][j]='.';
                        k++;
                    }
                    k=j+1;
                    while(k<n && board[i][k]=='X'){
                        board[i][k]='.';
                        k++;
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};

*/