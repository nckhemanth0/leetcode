class Solution {
public:
    int m,n;
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};
    using pi=pair<int,int>;
    using ti=tuple<int,int,int>;
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> safety(m,vector<int>(n,INT_MAX));
        queue<pi> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j});
                    safety[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int ni=i+x[k];
                int nj=j+y[k];
                if(ni>=0 && nj>=0 && ni<m && nj<n && safety[ni][nj]==INT_MAX){
                    safety[ni][nj]=safety[i][j]+1;
                    q.push({ni,nj});
                }
            }
        }

        priority_queue<ti> pq;
        vector<vector<int>> vis(m,vector<int>(n,0));
        pq.push({safety[0][0],0,0});
        int ans=INT_MAX;
        while(!pq.empty()){
            auto [val,i,j]=pq.top();
            ans=min(ans,val);
            if(i==m-1 && j==n-1){
                return ans;
            }
            pq.pop();
            for(int k=0;k<4;k++){
                int ni=i+x[k];
                int nj=j+y[k];
                if(ni>=0 && nj>=0 && ni<m && nj<n && !vis[ni][nj]){
                    vis[ni][nj]=1;
                    pq.push({safety[ni][nj],ni,nj});
                }
            }
        }
        return ans;
    }
};