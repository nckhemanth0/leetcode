class Solution {
public:
    int n;
    vector<int> ways;
    vector<int> lisDP;
    int rec(vector<int>& nums, int level){
        if(lisDP[level]!=-1){
            return lisDP[level];
        }
        int ans=1;
        ways[level]=1;
        for(int i=0;i<level;i++){
            if(nums[level]>nums[i]){
                if(ans<1+rec(nums,i)){
                    ans=1+rec(nums,i);
                    ways[level]=ways[i];
                }else if(ans==1+rec(nums,i)){
                    ways[level]+=ways[i];
                }
            }
        }
        return lisDP[level]=ans;
    }

    int findNumberOfLIS(vector<int>& nums) {
        n=nums.size();
        ways.resize(n+1,1);
        lisDP.resize(n+1,-1);
        int maxi=1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,rec(nums,i));
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(maxi==lisDP[i]){
                ans+=ways[i];
            }
        }
        return ans;
    }
};