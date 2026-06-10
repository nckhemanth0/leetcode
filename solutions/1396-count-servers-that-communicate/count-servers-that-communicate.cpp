class Solution {
public:
    int n,m;
    int dfs(int i,int j,vector<vector<int>> &grid){
        grid[i][j]=0;
        int ans=1;
        for(int k=0;k<n;k++){
            if(i>=0 && j>=0 && i<n && j<m && grid[k][j]==1 && i!=k){
                ans+=dfs(k,j,grid);
            }
        }
        for(int k=0;k<m;k++){
            if(i>=0 && j>=0 && i<n && j<m && grid[i][k]==1 && j!=k){
                ans+=dfs(i,k,grid);
            }
        }
        return ans;
    }
    int countServers(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int cnt=dfs(i,j,grid);
                    if(cnt>1){
                        ans+=cnt;
                    }
                }
            }
        }
        return ans;
    }
};