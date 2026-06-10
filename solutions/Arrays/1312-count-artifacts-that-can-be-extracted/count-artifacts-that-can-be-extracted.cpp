class Solution {
public:

    /*
        How indices are given int the question is very important in these questions!
        1-indexed / 0-indexed thoroughly check
    */

    vector<vector<int>> pre;
    void prefix_sum(int &n, vector<vector<int>>& dig){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                pre[i][j]=pre[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            }
        }
    }
    int sub_sum(int &r2,int &c2,int &r1,int &c1){
        return pre[r2+1][c2+1]-pre[r2+1][c1]-pre[r1][c2+1]+pre[r1][c1];
    }    

    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        pre.resize(n+1,vector<int>(n+1,0));
        for(auto x: dig){
            pre[x[0]+1][x[1]+1]=1;
        }
        prefix_sum(n,dig);
        int ans=0;
        for(auto x: artifacts){
            int r1=x[0],c1=x[1],r2=x[2],c2=x[3];
            if(sub_sum(r2,c2,r1,c1)==(r2-r1+1)*(c2-c1+1)){
                ans++;
            }
        }
        return ans;
    }
};