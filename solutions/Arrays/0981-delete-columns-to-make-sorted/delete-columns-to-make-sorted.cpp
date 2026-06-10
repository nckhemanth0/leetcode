class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rs=strs.size();
        int cs=strs[0].size();
        int ans=0;
        for(int c=0;c<cs;c++){
            bool sorted=true;
            for(int r=1;r<rs;r++){
                if(strs[r-1][c]>strs[r][c]){
                    sorted=false;
                    break;
                }
            }
            if(!sorted){
                ans++;
            }
        }
        return ans;
    }
};