class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int left=intervals[i][0];
            int right=intervals[i][1];
            if(right<=toBeRemoved[0]){
                ans.push_back(intervals[i]);
            }else if(left>=toBeRemoved[1]){
                ans.push_back(intervals[i]);
            }else{
                if(left<toBeRemoved[0]){
                    ans.push_back({left,toBeRemoved[0]});
                }
                if(right>toBeRemoved[1]){
                    ans.push_back({toBeRemoved[1],right});
                }
            }
        }
        return ans;
    }
};