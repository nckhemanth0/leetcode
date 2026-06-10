class UF{
private:
    vector<int> par;
    vector<int> sz;
public:
    UF(int n) : par(n), sz(n,1) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        return par[x]==x ? x : par[x]=find(par[x]);
    }
    bool merge(int x,int y){
        int rootx=find(x), rooty=find(y);
        if(rootx!=rooty){
            if(sz[rootx]<sz[rooty]){
                swap(rootx,rooty);
            }
            par[rooty]=rootx;
            sz[rootx]+=sz[rooty];
        }
        return false;
    }
};

class Solution {
public:
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};

    int latestDayToCross(int &row, int &col, vector<vector<int>>& cells){
        vector<vector<int>> grid(row,vector<int>(col,1));
        int n=cells.size();
        auto id=[&](int i,int j){
            return i*col+j;
        };
        int top=n, bottom=n+1;
        UF uf(n+2);
        for(int day=n-1;day>=0;day--){
            int i=cells[day][0]-1, j=cells[day][1]-1;
            grid[i][j]=0;
            int idx=id(i,j);
            if(i==0){
                uf.merge(n,idx);
            }
            if(i==row-1){
                uf.merge(n+1,idx);
            }
            for(int k=0;k<4;k++){
                int ni=i+x[k], nj=j+y[k];
                if(ni>=0 && nj>=0 && ni<row && nj<col && grid[ni][nj]==0){
                    uf.merge(idx,id(ni,nj));
                }
            }
            if(uf.find(n)==uf.find(n+1)){
                return day;
            }
        }
        return 1;
    }
};


/*
    Approach 4: DSU on WATER (forward time)
    Flood cells day by day and union WATER neighbors in 8 directions (diagonals included) [visualize]
    Use two virtual nodes: LEFT and RIGHT.
    The first day LEFT connects to RIGHT ⇒ an 8-connected water barrier exists, so no top→bottom LAND path can remain.
    Therefore, latest day to cross = (first day water barrier appears) - 1 (adjust by indexing: 0-based vs 1-based).
*/


class Solution__bin_search_BFS {
public:
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};

    bool check(int &mid, int &row, int &col, vector<vector<int>>& cells){
        vector<vector<int>> grid(row,vector<int>(col,0));
        for(int i=0;i<=mid;i++){
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        }
        queue<pair<int,int>> q;
        for(int j=0;j<col;j++){
            if(grid[0][j]==0){
                grid[0][j]=1;
                q.push({0,j});
            }
        }
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            int i=u.first, j=u.second;
            if(i==row-1){
                return true;
            }
            for(int k=0;k<4;k++){
                int ni=i+x[k], nj=j+y[k];
                if(ni>=0 && nj>=0 && ni<row && nj<col && grid[ni][nj]==0){
                    grid[ni][nj]=1;
                    q.push({ni,nj});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n=cells.size();
        int lo=0, hi=n-1, ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,row,col,cells)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans+1;
    }
};