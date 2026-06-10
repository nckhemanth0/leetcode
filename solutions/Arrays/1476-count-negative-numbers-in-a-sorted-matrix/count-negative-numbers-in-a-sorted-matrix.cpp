class Solution {
public:

    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        int i=0,j=n-1;
        while(j>=0 && i<m){
            if(grid[i][j]>=0){
                i++;
            }else{
                ans+=(m-i);
                j--;
            }
        }
        return ans;
    }

    // ====== ======= ======= ======= ======
    // still O(m*n) but in optimized way
    int countNegatives__mn(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        int mini_col=0;
        for(int i=m-1;i>=0;i--){
            int pos=false;
            if(grid[i][n-1]>=0){
                break;
            }
            for(int j=n-1;j>=mini_col;j--){
                if(grid[i][j]>=0){
                    pos=true;
                    mini_col=j+1;
                    break;
                }else{
                    ans++;
                }
            }
        }
        return ans;
    }
};