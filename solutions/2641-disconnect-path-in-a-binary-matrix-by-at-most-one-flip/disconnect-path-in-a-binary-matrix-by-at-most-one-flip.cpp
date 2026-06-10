class Solution {
public:
    int n,m;
    int x[2]={1,0};
    int y[2]={0,1};
    bool dfs(int i,int j,vector<vector<int>>& grid){
        if(i==n-1 && j==m-1){
            return true;
        }
        grid[i][j]=0;
        for(int k=0;k<2;k++){
            int ni=i+x[k];
            int nj=j+y[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1 && dfs(ni,nj,grid)){
                return true;
            }
        }
        return false;
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(!dfs(0,0,grid)){
            return true;
        }
        grid[0][0]=1;
        if(dfs(0,0,grid)){
            return false;
        }
        return true;
    }
};



/*



// actuay shortest dist here is i+j itself!
class Solution {
public:
    int n,m;
    int x[2]={1,0};
    int y[2]={0,1};
    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& ways,vector<vector<int>>& dist){
        queue<pair<int,int>> q;
        q.push({i,j});
        ways[0][0]=1;
        dist[0][0]=0;
        while(!q.empty()){
            auto &[ui,uj]=q.front();
            q.pop();
            if(ui==n-1 && uj==m-1){
                return;
            }
            for(int k=0;k<2;k++){
                int ni=ui+x[k];
                int nj=uj+y[k];
                if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1){
                    if(dist[ni][nj]==INT_MAX){
                        dist[ni][nj]=1+dist[ui][uj];
                        ways[ni][nj]=ways[ui][uj];
                        q.push({ni,nj});
                    }else{
                        ways[ni][nj]+=ways[ui][uj];
                    }
                }
            }
        }
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> ways(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        bfs(0,0,grid,ways,dist);
        return ways[n-1][m-1]<=1 && dist[n-1][m-1]>2;
    }
};

// i think here we dont need global dist be its only dag and keep moving forward!



*/