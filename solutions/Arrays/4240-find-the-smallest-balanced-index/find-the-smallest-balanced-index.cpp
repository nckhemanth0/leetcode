class Solution {
public:
    long long MAXI=LLONG_MAX;
    int smallestBalancedIndex(vector<int>& nums) {
        long long n=nums.size();
        vector<long long> sum(n+1,0);
        vector<long long> prod(n+1,1);
        for(int i=0;i<n;i++){
            sum[i+1]=(sum[i]+nums[i]);
        }
        long long ans=-1;
        for(long long i=n-1;i>=0;i--){
            long long left=sum[i];
            long long right=prod[i+1];
            if(left==right){
                if(ans!=-1){
                    ans=min(ans,i);
                }else{
                    ans=i;
                }
            }
            if(nums[i]!=0 && (MAXI/nums[i])<prod[i+1]){
                return ans;
            }
            prod[i]=(prod[i+1]*nums[i]);
        }
        return ans;
    }
};