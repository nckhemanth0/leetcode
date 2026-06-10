class Solution {
public:

    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};

    int n,m;

    void dfs(int i, int j, vector<vector<int>>& grid, int &cnt){
        cnt++;
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int ni=i+x[k], nj=j+y[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]!=0){
                dfs(ni,nj,grid,cnt);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        int cnt=0, ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){ // 0 mean visited
                    cnt=0;
                    dfs(i,j,grid,cnt);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }


    // ======

    int maxAreaOfIsland_STACK_FROM_REC(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        int ans = 0;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    std::stack<std::pair<int,int>> st;
                    st.push({i, j});
                    grid[i][j] = 0; // mark visited

                    while (!st.empty()) {
                        auto [r, c] = st.top();
                        st.pop();
                        ++area;

                        for (int k = 0; k < 4; ++k) {
                            int nr = r + dx[k];
                            int nc = c + dy[k];
                            if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1) {
                                grid[nr][nc] = 0; // mark visited as we push to avoid duplicates
                                st.push({nr, nc});
                            }
                        }
                    }

                    ans = std::max(ans, area);
                }
            }
        }
        return ans;
    }
};