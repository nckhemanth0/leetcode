class Solution {
public:
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        dist[entrance[0]][entrance[1]]=0;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int i=front.first;
            int j=front.second;
            for(int k=0;k<4;k++){
                int ni=i+x[k];
                int nj=j+y[k];
                if(ni>=0 && nj>=0 && ni<m && nj<n && maze[ni][nj]!='+' && dist[ni][nj]==INT_MAX){
                    dist[ni][nj]=dist[i][j]+1;
                    if(ni==0 || nj==0 || ni==m-1 || nj==n-1){
                        return dist[ni][nj];
                    }
                    q.push({ni,nj});
                }
            }
        }
        return -1;
    }
};