class Solution {
public:
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};
    int n,m;
    int dfs(int i,int j,vector<vector<int>>& grid){
        int sum=grid[i][j];
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int ni=i+x[k];
            int nj=j+y[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]){
                sum+=dfs(ni,nj,grid);
            }
        }
        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};