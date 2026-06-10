class Solution {
public:

    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};
    int n;

    void dfs(int i,int j,vector<vector<int>>& grid){
        grid[i][j]=2;
        for(int k=0;k<4;k++){
            int ni=i+x[k],nj=j+y[k];
            if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]==1){
                dfs(ni,nj,grid);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        int cnt=0;
        for(int i=0;i<n && cnt<1;i++){
            for(int j=0;j<n && cnt<1;j++){
                if(grid[i][j]==1){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto u=q.front();
            int i=u.first,j=u.second;
            q.pop();
            for(int k=0;k<4;k++){
                int ni=i+x[k],nj=j+y[k];
                if(ni>=0 && nj>=0 && ni<n && nj<n && dist[i][j]+1<dist[ni][nj]){ // or just can check !=1e9 too => dist[ni][nj]==1e9
                    dist[ni][nj]=dist[i][j]+1;
                    if(grid[ni][nj]==2){
                        return dist[i][j];
                    }
                    q.push({ni,nj});
                }
            }
        }
        return 0;
    }
};