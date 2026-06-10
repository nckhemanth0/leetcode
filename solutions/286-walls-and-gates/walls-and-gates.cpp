class Solution {
public:

    const int INF=2147483647;
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};
    struct state{
        int i;
        int j;
    };

    void wallsAndGates(vector<vector<int>>& rooms) {
        int n=rooms.size(), m=rooms[0].size();
        queue<state> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rooms[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            state st=q.front();
            q.pop();
            int i=st.i, j=st.j;
            for(int k=0;k<4;k++){
                int ni=i+x[k],nj=j+y[k];
                if(ni>=0 && nj>=0 && ni<n && nj<m && rooms[ni][nj]==INF){
                    rooms[ni][nj]=rooms[i][j]+1;
                    q.push({ni,nj});
                }
            }
        }
    }
};


