class Solution {
public:
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        // vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));
        
        vector<vector<int>> grid(n,vector<int>(m,0));
        for(auto x: sources){
            grid[x[0]][x[1]]=x[2];
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int r=front.first;
            int c=front.second;
            // if(vis[r][c]){
            //     continue;
            // }
            // vis[r][c]=true;
            for(int k=0;k<4;k++){
                int nr=r+x[k];
                int nc=c+y[k];
                if(!(nr>=0 && nc>=0 && nr<n && nc<m)){
                    continue;
                }
                if(dist[r][c]+1<dist[nr][nc]){
                    dist[nr][nc]=dist[r][c]+1;
                    grid[nr][nc]=max(grid[nr][nc],grid[r][c]);
                    q.push({nr,nc});
                }else if(dist[r][c]+1==dist[nr][nc]){
                    dist[nr][nc]=dist[r][c]+1;
                    grid[nr][nc]=max(grid[nr][nc],grid[r][c]);
                }
            }
        }
        return grid;
    }
};