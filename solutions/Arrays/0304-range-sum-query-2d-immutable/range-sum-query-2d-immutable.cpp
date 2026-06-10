class NumMatrix {
public:
    vector<vector<int>> prefix;
    int m,n;
    NumMatrix(vector<vector<int>>& matrix): m(matrix.size()),n(matrix[0].size()) {
        prefix=matrix;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i-1>=0){
                    prefix[i][j]+=prefix[i-1][j];
                }
                if(j-1>=0){
                    prefix[i][j]+=prefix[i][j-1];
                }
                if(i-1>=0 && j-1>=0){
                    prefix[i][j]-=prefix[i-1][j-1];
                }
            }
        }

    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int ans=prefix[r2][c2]
        - (c1-1>=0?prefix[r2][c1-1]:0)
        - (r1-1>=0?prefix[r1-1][c2]:0)
        +((r1-1>=0 && c1-1>=0)?prefix[r1-1][c1-1]:0);
        return ans;
    }
};

/*                              1-indexing
        class NumMatrix {
            int m;
            int n;
            vector<vector<int>> psum;
        public:
            NumMatrix(vector<vector<int>>& grid) {
                m = grid.size();
                n = grid[0].size();
                psum.resize(m+1, vector<int>(n+1, 0));
                for(int i =0; i < m ; ++i){
                    for(int j=0; j < n; ++j){
                        psum[i+1][j+1]  = psum[i+1][j]+psum[i][j+1] +grid[i][j]-psum[i][j];
                    }
                }
            }
            
            int sumRegion(int row1, int col1, int row2, int col2) {
                return psum[row2+1][col2+1] - psum[row2+1][col1] - psum[row1][col2+1] +psum[row1][col1];
            }
*/

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

