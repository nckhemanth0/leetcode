class Solution {
public:

    // prefix sum+maps solution
    // sub problem: find longest length subarray with sum-x => then other elements form smallest circular subarray
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        long long total_sum=0,sum=0,not_ans=-1;
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
        }
        if(x==total_sum){
            return n;
        }
        long long nx=total_sum-x;
        unordered_map<int,int> pre_sum_idx;
        pre_sum_idx[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(pre_sum_idx.count(sum-nx)){
                not_ans=max(not_ans,1LL*i-pre_sum_idx[sum-nx]);
            }
            if(pre_sum_idx.count(sum)==0){
                pre_sum_idx[sum]=i;
            }
        }
        if(not_ans==-1){
            return not_ans;
        }
        return n-not_ans;
    }


    // prefix sum+maps solution
    // sub problem: find longest length subarray with sum-x => then other elements form smallest circular subarray
    int minOperations__sliding_window(vector<int>& nums, int x) {
        int n=nums.size();
        long long total_sum=0,sum=0,not_ans=-1;
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
        }
        if(x==total_sum){
            return n;
        }
        long long nx=total_sum-x;
        int left=0,right=0;
        for(;right<n;right++){
            sum+=nums[right];
            while(sum>nx && left < right){
                sum-=nums[left];
                left++;
            }
            if(sum==nx){ // only sum==nx is valid window, not sum<=nx!!
                not_ans=max(not_ans,1LL*right-left+1);
            }
        }
        if(not_ans==-1){
            return not_ans;
        }
        return n-not_ans;
    }





/*                  
                        CORRECTNESS is there  BUT MLE due to constraints
    int n;
    vector<vector<int>> dp;
    int rec(int i, int j, int x, vector<int>& nums){
        if(x<0){
            return 1e9;
        }
        if(x==0){
            return 0;
        }
        if(i>j){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=min(rec(i+1,j,x-nums[i],nums), rec(i,j-1,x-nums[j],nums))+1;
    }

    // MLE!!! but correctess is there :)
    int minOperations(vector<int>& nums, int x) {
        n=nums.size();
        dp.resize(n,vector<int>(n,-1));
        int ans=rec(0,n-1,x,nums);
        return (ans>=1e9)?-1:ans;
    }

*/

};