class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n+1,INT_MIN);
        vector<int> suf(n+1,INT_MAX);
        for(int i=0;i<n;i++){
            pre[i+1]=max(pre[i],nums[i]);
        }
        for(int j=n-1;j>=0;j--){
            suf[j]=min(suf[j+1],nums[j]);
        }
        for(int i=0;i<n;i++){
            if(pre[i+1]-suf[i]<=k){
                return i;
            }
        }
        return -1;
    }
};