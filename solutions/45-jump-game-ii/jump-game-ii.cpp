class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int last=0;
        int l=0,r=0,farthest=0,jumps=0;
        while(l<n){
            for(int j=l;j<=r;j++){
                farthest=max(farthest,j+nums[j]);
            }
            l=r+1;
            r=farthest;
            jumps++;
            if(farthest>=n-1){
                return jumps;
            }
        }
        return jumps;
    }
};