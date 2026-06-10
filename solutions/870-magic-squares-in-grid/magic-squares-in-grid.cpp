

// TODO: Understand solution intuition and sequences!!

/*
    Mine is overkill!!!

    EASIEST:
            bool isMagic3x3(vector<vector<int>>& g, int r, int c){
                int mask = 0;
                int row[3]={0}, col[3]={0};
                int d1=0, d2=0;

                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        int v = g[r+i][c+j];
                        if(v<1 || v>9) return false;
                        int bit = 1<<v;
                        if(mask & bit) return false;
                        mask |= bit;

                        row[i] += v;
                        col[j] += v;
                        if(i==j) d1 += v;
                        if(i+j==2) d2 += v;
                    }
                }

                if(d1 != 15 || d2 != 15) return false;
                for(int k=0;k<3;k++){
                    if(row[k] != 15 || col[k] != 15) return false;
                }
                return true;
            }
*/


class Solution {
public:
    int m,n;
    vector<vector<int>> pre;
    vector<vector<int>> getPrefix(vector<vector<int>>& grid){
        pre.assign(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pre[i+1][j+1]=grid[i][j]+pre[i][j+1]+pre[i+1][j]-pre[i][j];
            }
        }
        return pre;
    }
    int getSum_pre(int r2, int c2, int r1, int c1){
        return pre[r2+1][c2+1]-pre[r2+1][c1]-pre[r1][c2+1]+pre[r1][c1];
    }

    vector<vector<int>> preDiag1; // ↘  (r-1,c-1)
    vector<vector<int>> getDiag1Prefix(vector<vector<int>>& grid){
        preDiag1.assign(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                preDiag1[i+1][j+1] = grid[i][j] + preDiag1[i][j];
            }
        }
        return preDiag1;
    }
    int getSum_diag1(int r2, int c2, int r1, int c1){
        return preDiag1[r2+1][c2+1] - preDiag1[r1][c1];
    }

    vector<vector<int>> preDiag2; // ↙  (r-1,c+1)
    vector<vector<int>> getDiag2Prefix(vector<vector<int>>& grid){
        preDiag2.assign(m+1, vector<int>(n+2, 0)); 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                preDiag2[i+1][j+1] = (int)grid[i][j] + preDiag2[i][j+2];
            }
        }
        return preDiag2;
    }
    int getSum_diag2(int r2, int c2, int r1, int c1){
        return preDiag2[r2+1][c2+1] - preDiag2[r1][c1+2];
    }



    int numMagicSquaresInside(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        int ans=0;
        pre=getPrefix(grid);
        preDiag1=getDiag1Prefix(grid);
        preDiag2=getDiag2Prefix(grid);

        for(int i=2;i<m;i++){
            for(int j=2;j<n;j++){
                int mask = 0;
                bool ok = true;
                for(int r=i-2; r<=i && ok; r++){
                    for(int c=j-2; c<=j; c++){
                        int v = grid[r][c];
                        if(v < 1 || v > 9){ ok = false; break; }
                        int bit = 1 << v;
                        if(mask & bit){ ok = false; break; }
                        mask |= bit;
                    }
                }
                if(!ok) continue;
                if(grid[i-1][j-1] != 5) continue;
                int r1=getSum_pre(i-2,j,i-2,j-2);
                int r2=getSum_pre(i-1,j,i-1,j-2);
                int r3=getSum_pre(i,j,i,j-2);
                int c1=getSum_pre(i,j-2,i-2,j-2);
                int c2=getSum_pre(i,j-1,i-2,j-1);
                int c3=getSum_pre(i,j,i-2,j);
                int d1=getSum_diag1(i,j,i-2,j-2);
                int d2=getSum_diag2(i,j-2,i-2,j);
                if(r1==r2 && r1==r3 && r1==c1 && r1==c2 && r1==c3 && r1==d1 && r1==d2){
                    ans++;
                }
            }
        }
        return ans;
    }
};