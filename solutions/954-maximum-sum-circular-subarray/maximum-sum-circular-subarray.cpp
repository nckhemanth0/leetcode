class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int cur_max=0, max_so_far=INT_MIN,min_so_far=INT_MAX,cur_min=0,total_sum=0;
        for(int i=0;i<n;i++){
            cur_max=max(nums[i],nums[i]+cur_max);
            max_so_far=max(max_so_far,cur_max);
            
            cur_min=min(nums[i],nums[i]+cur_min);
            min_so_far=min(min_so_far,cur_min);

            total_sum+=nums[i];
        }
        return max_so_far>0?max(max_so_far,total_sum-min_so_far):max_so_far;
    }

    // ======= ======= Prefix and suffix sum for circular sum ======= =======

    int maxSubarraySumCircular__prefix_suffix(vector<int>& nums) {
        int n=nums.size();

        vector<int> suffix_sum(n+1,0);
        vector<int> right_sum_max(n+1,0);
        for(int i=n-1;i>=0;i--){
            suffix_sum[i]=suffix_sum[i+1]+nums[i];
            right_sum_max[i]=max(right_sum_max[i+1],suffix_sum[i]);
        }

        int cur_max=0, max_so_far=INT_MIN,prefix_sum=0;
        for(int i=0;i<n;i++){
            cur_max=max(nums[i],nums[i]+cur_max);
            max_so_far=max(max_so_far,cur_max);
            prefix_sum+=nums[i];
            if(i+1<n){
                max_so_far=max({max_so_far,prefix_sum+right_sum_max[i+1]});
            }
        }
        return max_so_far;
    }
};