class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int mod_sum=0;
        unordered_map<int,int> sum_idx;
        sum_idx[0]=-1;
        for(int i=0;i<n;i++){
            mod_sum=(mod_sum+nums[i])%k;
            if(sum_idx.count(mod_sum)){
                if(i-sum_idx[mod_sum]>=2){
                    return true;
                }
            }else{
                sum_idx[mod_sum]=i;
            }
        }
        return false;
    }
};