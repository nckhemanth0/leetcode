class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size(),par_left=0,ans=0;
        vector<bool> par_right(n,0);
        for(int i=n-1;i>=0;i--){
            par_right[i]=(((i+1<n)?(int)par_right[i+1]:0)+nums[i])%2;
        }
        for(int i=0;i<n-1;i++){
            par_left=(par_left+nums[i]%2);
            if(abs(par_left-(int)par_right[i+1])%2==0){
                ans++;
            }
        }
        return ans;
    }
};