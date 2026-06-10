class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        bool ans=1;
        // vector<int> pre(n,-1);
        // pre[0]=(nums[0]==1)?0:-1;
        int last_one=(nums[0]==1)?0:-1;
        for(int i=1;i<n;i++){
            if(nums[i]==1){
                if(last_one!=-1){
                    ans&=(i-last_one-1>=k);
                }
                last_one=i;
            }
        }
        return ans;
    }
};