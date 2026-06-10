class Solution {
public:
    #define f first
    #define s second
    vector<vector<int>> vis;
    int n,m;
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};
    int ans=0;
    bool isWallOrBoundary(int i, int j, vector<vector<int>>& maze){
        return i<0 || j<0 || i>=n || j>=m || maze[i][j]==1;
    }
    void dfs(pair<int,int> u, pair<int,int> prev, pair<int,int> end, int state, vector<vector<int>>& maze){
        // cout<<u.f<<" "<<u.s<<endl;
        if(ans){
            return;
        }
        if(state!=-1){
            int nf=u.f+x[state], ns=u.s+y[state];
            if(isWallOrBoundary(nf,ns,maze)){
                state=-1;
            }else{
                dfs({nf,ns},u,end,state,maze);
            }
        }
        if(u==end && state==-1){
            ans=1;
            return;
        }
        if(state==-1 && !vis[u.f][u.s]){
            vis[u.f][u.s]=1;
            for(int k=0;k<4;k++){
                int nf=u.f+x[k], ns=u.s+y[k];
                pair<int,int> temp={nf,ns};
                if(!isWallOrBoundary(nf,ns,maze)){
                    dfs(temp,u,end,k,maze);
                }
            }
        }
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        /*
            -1 => rest
            0 => left
            1 => top
            2 => right
            3 => bottom
        */
        n=maze.size(),m=maze[0].size();
        vis.resize(n,vector<int>(m,0));
        dfs({start[0],start[1]},{-1,-1},{destination[0],destination[1]},-1,maze);
        return ans;
    }
};