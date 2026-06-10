class Solution {
public:

    int max_window_subarray_sum_le_k(vector<vector<int>> &merged, int k){
        int n=merged.size(), head=0, tail=0, sum=0,ans=0;
        while(tail<n){
            while((head+1<n) && merged[head+1][0]-merged[tail][1]<=k){
                head++;
            }
            ans=max(ans,head-tail+1);
            tail++;
            // this is good to have and still works if not kept, since head-tail is neg
            // and also in while loop, It “self-heals” automatically => since merged[head+1][0]-merged[tail][1]<=k is always true during backlog
            if(head<tail){
                head=tail;
            }
        }
        return ans;
    }

    int minConnectedGroups(vector<vector<int>>& intervals, int k) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        for(int i=0;i<n;i++){
            if(merged.empty() || intervals[i][0]>merged.back()[1]){
                merged.push_back(intervals[i]);
            }else{
                merged.back()[1]=max(merged.back()[1], intervals[i][1]);
            }
        }
        int window=max_window_subarray_sum_le_k(merged, k);
        return merged.size()-window+1;
    }
};