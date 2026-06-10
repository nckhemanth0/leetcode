class Solution {
public:
    int si,sj,ei,ej,m,n;
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};

    vector<vector<vector<int>>> dp;
    int fullMask=0;

    int rec(int i, int j, int mask, vector<vector<int>>& grid){
        if(i==ei && j==ej){
            return mask==fullMask;
        }

        if(dp[i][j][mask]!=-1) return dp[i][j][mask];

        int ans=0;
        for(int k=0;k<4;k++){
            int ni=i+x[k],nj=j+y[k];
            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]!=-1){
                int bit=(ni*n+nj);
                if((mask>>bit)&1) continue;
                ans+=rec(ni,nj,mask|(1<<bit),grid);
            }
        }
        return dp[i][j][mask]=ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=-1){
                    fullMask|=(1<<(i*n+j));
                }
                if(grid[i][j]==2){
                    ei=i;
                    ej=j;
                }
                if(grid[i][j]==1){
                    si=i;
                    sj=j;
                }
            }
        }

        dp.assign(m,vector<vector<int>>(n,vector<int>(1<<(m*n),-1)));

        int startMask=(1<<(si*n+sj));
        return rec(si,sj,startMask,grid);
    }
};







class Solution1 {
public:
    int si,sj,ei,ej,m,n;
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};
    vector<vector<int>> vis;
    int rec(int i, int j, int cnt, vector<vector<int>>& grid){
        // cout<<i<<" "<<j<<" "<<cnt<<endl;
        int ans=0;
        for(int k=0;k<4;k++){
            int ni=i+x[k],nj=j+y[k];
            if(ni>=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj]){
                if(grid[ni][nj]==0){
                    vis[ni][nj]=1;
                    ans+=rec(ni,nj,cnt-1,grid);
                    vis[ni][nj]=0;
                }else if(grid[ni][nj]==2 && ni==ei && nj==ej && cnt==0){
                    return 1;
                }

            }
        }
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int cnt=0;
        vis.resize(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    cnt++;
                }
                if(grid[i][j]==2){
                    ei=i;
                    ej=j;
                }
                if(grid[i][j]==1){
                    si=i;
                    sj=j;
                }
            }
        }
        return rec(si,sj,cnt,grid);
    }
};