class Solution {
public:
    /*
        question, example, thought
    */
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n,0));
        for(auto x: queries){
            int r1=x[0],c1=x[1],r2=x[2],c2=x[3];
            mat[r1][c1]++;
            if(c2+1<n){
                mat[r1][c2+1]-=1;
            }
            if(r2+1<n){
                mat[r2+1][c1]-=1;
            }
            if(r2+1<n && c2+1<n){
                mat[r2+1][c2+1]+=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int ans=0;
                if(i-1>=0){
                    ans+=mat[i-1][j];
                }
                if(j-1>=0){
                    ans+=mat[i][j-1];
                }
                if(i-1>=0 && j-1>=0){
                    ans-=mat[i-1][j-1];
                }
                ans+=mat[i][j];
                mat[i][j]=ans;
            }
        }
        return mat;
    }
};