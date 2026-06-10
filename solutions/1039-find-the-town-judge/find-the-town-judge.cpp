class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in_minus_out(n+1, 0);
        for(auto x: trust){
            in_minus_out[x[1]]++;
            in_minus_out[x[0]]--;
        }
        for(int i=1;i<=n;i++){
            if(in_minus_out[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};