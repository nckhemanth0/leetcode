class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int m=capacity.size();
        sort(capacity.begin(),capacity.end(),greater<int>());
        int sum=accumulate(apple.begin(), apple.end(), 0);
        for(int i=0;i<m;i++){
            sum-=capacity[i];
            if(sum<=0){
                return i+1;
            }
        }
        return -1;
    }
};