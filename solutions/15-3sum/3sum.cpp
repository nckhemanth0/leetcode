class Solution {
public:
    int n;
    vector<vector<int>> threeSum(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end()); // -4,-1,-1,0,1,2
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){

            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return ans;
    }
};