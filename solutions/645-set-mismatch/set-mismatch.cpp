class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size(),repeat,sum=0;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            if(s.count(nums[i])!=0){
                repeat=nums[i];
            }
            s.insert(nums[i]);
            sum+=nums[i];
        }
        int toalSum=n*(n+1)/2;
        return {repeat,toalSum+repeat-sum};
    }
};