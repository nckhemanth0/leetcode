class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int> diff(n+1,0);
        for(auto x: lights){
            int l=max(0,x[0]-x[1]);
            int r=min(n-1,x[0]+x[1]);
            diff[l]++;
            diff[r+1]--;
        }
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i]=(i>=1?prefix[i-1]:0)+diff[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(prefix[i]>=requirement[i]){ // could have directly run over sum of diff instead of seperate prefix sum 
                ans++;
            }
        }
        return ans;
    }
};