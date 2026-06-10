class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size(),ans=0;
        for(int i=1;i<n;i++){
            int dx=abs(points[i][0]-points[i-1][0]),dy=abs(points[i][1]-points[i-1][1]);
            // (or) ans+=max(dx,dy);
            ans+=dx+dy-min(dx,dy);
        }
        return ans;
    }
};