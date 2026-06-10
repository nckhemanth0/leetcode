class Solution {
public:
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};
    int n,m;
    bool dfs(int i, int j, vector<vector<int>>& grid){
        if(!(i>=0 && j>=0 && i<n && j<m)){
            return false;
        }
        if(grid[i][j]){
            return true;
        }
        grid[i][j]=1;
        bool ans=true;
        for(int k=0;k<4;k++){
            int ni=i+x[k];
            int nj=j+y[k];
            if(!dfs(ni,nj,grid)){
                ans=false;
            }
        }
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && dfs(i,j,grid)){
                    ans++;
                }
            }
        }
        return ans;
    }
};