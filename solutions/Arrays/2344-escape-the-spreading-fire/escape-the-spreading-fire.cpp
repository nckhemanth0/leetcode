class Solution {
public:
    int m,n;
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};
    bool check(int mid,vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        vector<vector<int>> fire(m,vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    fire[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int ni=i+x[k];
                int nj=j+y[k];
                if(ni>=0 && nj>=0 && ni<m && nj<n && grid[ni][nj]!=2 && fire[ni][nj]==INT_MAX){
                    fire[ni][nj]=fire[i][j]+1;
                    q.push({ni,nj});
                }
            }
        }
        q={};
        q.push({0,0});
        vector<vector<int>> person(m,vector<int>(n,INT_MAX));
        person[0][0]=mid;
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int ni=i+x[k];
                int nj=j+y[k];
                if(ni>=0 && nj>=0 && ni<m && nj<n && grid[ni][nj]!=2 && person[ni][nj]==INT_MAX){
                    if((ni==m-1 && nj==n-1 && 1+person[i][j]<=fire[ni][nj]) || (1+person[i][j]<fire[ni][nj])){
                        person[ni][nj]=person[i][j]+1;
                        q.push({ni,nj});
                    }
                }
            }
        }
        return person[m-1][n-1]!=INT_MAX;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int lo=0,hi=m*n;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,grid)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return (ans==m*n)?1e9:ans;
    }
};