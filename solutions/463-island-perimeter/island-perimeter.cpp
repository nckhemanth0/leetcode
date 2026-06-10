class Solution {
public:
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int ni=i+x[k], nj=j+y[k];
                        if(ni<0 || nj<0 || ni>=n || nj>=m || grid[ni][nj]==0){
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};