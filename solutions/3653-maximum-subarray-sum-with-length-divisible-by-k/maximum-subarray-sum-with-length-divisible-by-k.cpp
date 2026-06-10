class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long n=nums.size();
        unordered_map<long long,long long> size_idx;
        size_idx[0]=0;
        long long sum=0,ans=-1e15;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            long long idx=(i+1)%k;
            if(size_idx.count(idx)){
                ans=max(ans,sum-size_idx[idx]);
            }
            if(size_idx.count(idx)==0){
                size_idx[idx]=1e15;
            }
            size_idx[idx]=min(size_idx[idx],sum);
        }
        return ans;
    }
};