class Solution {
public:
    int m;
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        m=grid.size();
        for(int i=0;i<m;i++){
            vector<int> v;
            for(int j=0;j<=m-i-1;j++){ // j is count
                v.push_back(grid[i+j][j]);
            }
            sort(v.rbegin(),v.rend());
            for(int j=0;j<=m-i-1;j++){ // j is count
                grid[i+j][j]=v[j];
                
            }
        }
        for(int j=1;j<=m-1;j++){
            vector<int> v;
            for(int i=0;i<=m-j-1;i++){ // j is count
                v.push_back(grid[i][j+i]);
            }
            sort(v.begin(),v.end());
            for(int i=0;i<=m-j-1;i++){ // j is count
                grid[i][j+i]=v[i];
            }
        }
        return grid;
    }
};