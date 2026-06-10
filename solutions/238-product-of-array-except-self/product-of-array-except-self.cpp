class Solution {
public:

// this is common pattern of running prefix of suffix instead of precomputing these prior and just doing plain iteration using that precompute
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        ans[0]=1;
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int suffix_prod=1;
        for(int i=n-1;i>=0;i--){
            ans[i]=ans[(i+1)-1]*suffix_prod;
            suffix_prod=suffix_prod*nums[i];
        }
        return ans;
    }
    vector<int> productExceptSelf_1(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n+1,1);
        vector<int> suffix(n+1,1);
        vector<int> v;
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        for(int i=n-1;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }
        for(int i=0;i<n;i++){
            // for index i of array, prefix corresponding index is (i+1)
            // for index i of array, suffix corresponding index is (i) bc we did: suffix[i]=suffix[i+1]*nums[i];
            v.push_back(prefix[(i+1)-1]*suffix[(i)+1]);
        }
        return v;
    }
};