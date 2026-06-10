class Solution {
public:
    vector<int> vis;
    vector<int> ans;
    vector<int> final_ans;
    int n;
    int found=0;
    void rec(int level, int x){
        if(found){
            return;
        }
        if(level==(1<<n)){
            final_ans=ans;
            found=1;
            return;
        }
        for(int i=0;i<n;i++){
            int nx=(1<<i)^x;
            if(!vis[nx] && nx>=0 && nx<=((1<<n)-1)){
                vis[nx]=1;
                ans.push_back(nx);
                rec(level+1,nx);
                ans.pop_back();
                vis[nx]=0;
            }
        }
    }

    vector<int> grayCode(int N) {
        n=N;
        vis.resize((1<<n),0);
        vis[0]=1;
        ans.push_back(0);
        rec(1,0);
        return final_ans;
    }
};