class Solution {
public:
    #define INF 1e18
    int n,m;
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};

    void dfs(int i, int j, vector<vector<int>>& ocean, vector<vector<int>>& heights){
        ocean[i][j]=1; // visit
        for(int k=0;k<4;k++){
            int ni=i+x[k], nj=j+y[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m){
                if(ocean[ni][nj]!=1 && heights[i][j]<=heights[ni][nj]){
                    dfs(ni,nj,ocean,heights);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size(),m=heights[0].size();
        vector<vector<int>> pac(n, vector<int>(m,0));
        vector<vector<int>> atl(n, vector<int>(m,0));
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    dfs(i,j,pac,heights);
                }
                if(j==m-1 || i==n-1){
                    dfs(i,j,atl,heights);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};