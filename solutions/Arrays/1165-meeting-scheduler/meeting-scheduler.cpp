class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(),slots1.end());
        sort(slots2.begin(),slots2.end());
        int i=0,j=0;
        while(i<slots1.size() && j<slots2.size()){
            int lo=max(slots1[i][0],slots2[j][0]);
            int hi=min(slots1[i][1],slots2[j][1]);
            if(lo<hi && hi-lo>=duration){
                return {lo,lo+duration};
            }
            if(slots1[i][1]<slots2[j][1]){
                i++;
            }else{
                j++;
            }
        }
        return {};
    }
};