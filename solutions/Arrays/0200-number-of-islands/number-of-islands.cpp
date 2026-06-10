class Solution {
public:

    // 3 SOLUTIONS - DFS, BFS, UF

    int n,m;

    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};

    struct state{
        int f;
        int s;

        // important for comparision
        bool operator==(const state& other) const { return f == other.f && s == other.s; }
        bool operator!=(const state& other) const { return !(*this == other); }
    };

    // 2d union find
    class UF{
    private:
        vector<vector<state>> parent;
        vector<vector<int>> rank;
        int cnt=0; // tracking total number of merges done
    public:
        UF(int n,int m){
            parent.resize(n);
            rank.resize(n);
            for(int i=0;i<n;i++){
                parent[i].resize(m);
                rank[i].resize(m);
                for(int j=0;j<m;j++){
                    parent[i][j]={i,j};
                    rank[i][j]=0;
                }
            }
        }
        state find(state st){
            if(parent[st.f][st.s]!=st){
                return parent[st.f][st.s]=find(parent[st.f][st.s]);
            }
            return st;
        }
        void merge(state st1,state st2){
            state par1=find(st1), par2=find(st2);
            if(par1!=par2){
                if(rank[par1.f][par1.s]<rank[par2.f][par2.s]){
                    swap(par1,par2);
                }
                parent[par2.f][par2.s]=parent[par1.f][par1.s];
                rank[par1.f][par1.s]++;
                cnt++;
            }
        }
        int getCount(){
            return cnt;
        }
    };

    // UF
    int numIslands_UF(vector<vector<char>>& grid) {
        n=grid.size(), m=grid[0].size();
        int cnt=0;
        UF uf(n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    for(int k=0;k<4;k++){
                        int ni=i+x[k], nj=j+y[k];
                        if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]!='0'){
                            uf.merge({i,j},{ni,nj});
                        }
                    }
                }
            }
        }
        // initial count of components is cnt
        // as we merge in UF, # of components will be cnt-1
        return cnt-uf.getCount();
    }

    // Time complexity : O(M×N) where M is the number of rows and
    // N is the number of columns. Note that Union operation takes essentially constant
    // time1 when UnionFind is implemented with both path compression and union by rank.

    // Space complexity : O(M×N) as required by UnionFind data structure.


                                

    //  ==========================================

    int numIslands_BFS(vector<vector<char>>& grid) {
        n=grid.size(), m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    queue<state> q;
                    q.push({i,j});
                    while(!q.empty()){
                        state u=q.front();
                        q.pop();
                        grid[u.f][u.s]='0';
                        for(int k=0;k<4;k++){
                            int ni=u.f+x[k], nj=u.s+y[k];
                            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]!='0'){
                                grid[ni][nj]='0';
                                q.push({ni,nj});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }

    // Time complexity : O(M×N) where M is the number of rows and
    // N is the number of columns.

    // Space complexity : O(min(M,N)) because in worst case where the
    // grid is filled with lands, the size of queue can grow up to min(M,N).

    //  ==========================================


    void dfs(int i, int j, vector<vector<char>>& grid){
        grid[i][j]='0'; // visited
        for(int k=0;k<4;k++){
            int ni=i+x[k], nj=j+y[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]!='0'){
                dfs(ni,nj,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n=grid.size(), m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    // Time complexity : O(M×N) where M is the number of rows and
    // N is the number of columns.

    // Space complexity : worst case O(M×N) in case that the grid map
    // is filled with lands where DFS goes by M×N deep.
};