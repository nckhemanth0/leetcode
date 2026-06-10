class Solution {
public:

    vector<vector<int>> pre_mat;

    struct coord {
        int r;
        int c;
    };

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        pre_mat.resize(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pre_mat[i+1][j+1]=mat[i][j]+pre_mat[i][j+1]+pre_mat[i+1][j]-pre_mat[i][j];
            }
        }
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                auto [r1,c1]=coord{min(i+k+1,m),min(j+k+1,n)};
                auto [r2,c2]=coord{max(0,i-k),max(0,j-k)};
                ans[i][j]=pre_mat[r2][c2]-pre_mat[r2][c1]-pre_mat[r1][c2]+pre_mat[r1][c1];
            }
        }
        return ans;
    }
};