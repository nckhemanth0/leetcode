class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        unordered_map<int,int> pre_sum_index;
        pre_sum_index[0]=-1;
        long long ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(pre_sum_index.count(sum-k)){
                ans=max(ans,1LL*i-pre_sum_index[sum-k]);
            }
            if(pre_sum_index.count(sum)==0){
                // just update when we first see this sum
                pre_sum_index[sum]=i;
            }
        }
        return ans;
    }
};