class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,set<int>> pre_xor_idx;
        pre_xor_idx[0].insert(-1);
        int xorr=0,ans=0;
        for(int i=0;i<n;i++){
            xorr^=nums[i];
            if(pre_xor_idx.count(xorr)){
                for(auto l_idx: pre_xor_idx[xorr]){
                    l_idx+=1;
                    ans+=(i-l_idx);
                }
            }
            pre_xor_idx[xorr].insert(i);
        }
        return ans;
    }
};