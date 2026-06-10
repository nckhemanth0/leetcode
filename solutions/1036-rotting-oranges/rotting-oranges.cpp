class Solution {
public:

    class state{
        public:
            int r,c;
    };

    int INF=1e9;

    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};

    // without dist and using dummy node for max levels and in-place graph update for vis check
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), ans=0, fresh_oranges=0;
        queue<state> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh_oranges++;
                }
            }
        }
        int ans_levels=-1;
        q.push({-1,-1});
        while(!q.empty()){
            state u=q.front();
            q.pop();
            if(u.r==-1){
                ans_levels++;
                if(!q.empty()){
                    q.push({-1,-1});
                }
                continue;
            }
            for(int k=0;k<4;k++){
                int nr=u.r+x[k], nc=u.c+y[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                    fresh_oranges--;
                }
            }
        }
        return fresh_oranges==0 ? ans_levels : -1;
    }


    // ========================== ========================== ==========================


    // with dist as visited and tracking max (shortest distance)
    int orangesRotting__extra_space(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), ans=0, fresh_oranges=0;
        vector<vector<int>> dist(m,vector<int>(n,INF));
        queue<state> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    dist[i][j]=0;
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh_oranges++;
                }
            }
        }
        while(!q.empty()){
            state u=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=u.r+x[k], nc=u.c+y[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && dist[nr][nc]==INF){
                    dist[nr][nc]=dist[u.r][u.c]+1;
                    q.push({nr,nc});
                    ans=max(ans,dist[nr][nc]);
                    fresh_oranges--;
                }
            }
        }
        return fresh_oranges==0 ? ans : -1;
    }
};

/*
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        int minutes = 0;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            int sz = q.size();
            bool changed = false;

            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto &[dx, dy] : dir) {
                    int nx = x + dx, ny = y + dy;

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                        changed = true;
                    }
                }
            }

            if (changed) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};

*/