class Solution {
    int[] x={0,-1,0,1};
    int[] y={-1,0,1,0};
    int m,n;
    void dfs(int i, int j, char[][] grid){
        grid[i][j]='0';
        for(int k=0;k<4;k++){
            int ni=i+x[k], nj=j+y[k];
            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]=='1'){
                dfs(ni,nj,grid);
            }
        }
    }
    public int numIslands(char[][] grid) {
        m=grid.length;
        n=grid[0].length;
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
}