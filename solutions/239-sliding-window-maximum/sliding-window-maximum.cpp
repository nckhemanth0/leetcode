class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<n;i++){
            //insert
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);

            //remove
            if(i-k>=0){
                // is i-k index there?
                while(dq.front()<=(i-k)){
                    dq.pop_front();
                }
            }
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};