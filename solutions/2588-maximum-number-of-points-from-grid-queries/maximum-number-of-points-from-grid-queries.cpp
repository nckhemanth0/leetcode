class Solution {
public:
    using ti=tuple<int,int,int>;
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};
    int m,n;
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        m=grid.size();
        n=grid[0].size();
        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        priority_queue<ti,vector<ti>,greater<ti>> pq;
        vector<vector<int>> vis(m,vector<int>(n,0));
        pq.push({grid[0][0],0,0});
        vis[0][0]=1;
        vector<int> ans(q.size(),-1);
        int sum=0;
        for(int i=0;i<q.size();i++){
            int temp=0;
            while(!pq.empty() && get<0>(pq.top())<q[i].first){
                auto [val,i,j]=pq.top();
                temp+=1;
                pq.pop();
                for(int k=0;k<4;k++){
                    int ni=i+x[k];
                    int nj=j+y[k];
                    if(ni>=0 && nj>=0 && ni<m && nj<n && !vis[ni][nj]){
                        vis[ni][nj]=1;
                        pq.push({grid[ni][nj],ni,nj});
                    }
                }
            }
            sum+=temp;
            ans[q[i].second]=sum;
        }
        return ans;
    }
};