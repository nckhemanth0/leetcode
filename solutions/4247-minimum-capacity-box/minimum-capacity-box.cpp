class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n=capacity.size();
        int minIndex=-1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int diff=capacity[i]-itemSize;
            if(capacity[i]>=itemSize && ans>diff){
                ans=min(ans,capacity[i]-itemSize);
                minIndex=i;
            }
        }
        return minIndex;
    }
};