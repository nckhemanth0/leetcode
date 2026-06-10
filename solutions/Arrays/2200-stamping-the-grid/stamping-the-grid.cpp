class Solution {
public:

    using ll=long long;

    vector<vector<int>> pre;

    // void print(vector<vector<int>> mat){
    //     for(int i=0;i<mat.size();i++){
    //         for(int j=0;j<mat[0].size();j++){
    //             cout<<mat[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }

    bool is_occupied_submatrix(int r2,int c2, int r1,int c1){
        int cnt=pre[r2+1][c2+1]-pre[r2+1][c1]-pre[r1][c2+1]+pre[r1][c1];
        return cnt>=1;
    }

    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m=grid.size(), n=grid[0].size();
        pre.resize(m+1,vector<int>(n+1,0)); // (0,0) is filler
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pre[i+1][j+1]=(grid[i][j]==1)+pre[i+1][j]+pre[i][j+1]-pre[i][j];
            }
        }
        vector<vector<ll>> diff(m+1,vector<ll>(n+1,0)); // (m,n) is filler
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r1=(i-stampHeight+1), c1=(j-stampWidth+1);
                int r2=i,c2=j;
                if(r1<0 || c1<0 || is_occupied_submatrix(r2,c2,r1,c1)){
                    continue;
                }
                diff[r1][c1]+=1;
                diff[r2+1][c1]-=1;
                diff[r1][c2+1]-=1;
                diff[r2+1][c2+1]+=1;
            }
        }
        // prefix sum of diff array
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i){
                    diff[i][j]+=diff[i-1][j];
                }
                if(j){
                    diff[i][j]+=diff[i][j-1];
                }
                if(i&&j){
                    diff[i][j]-=diff[i-1][j-1];
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && diff[i][j]==0){
                    return false;
                }
            }
        }
        return true;
    }
};