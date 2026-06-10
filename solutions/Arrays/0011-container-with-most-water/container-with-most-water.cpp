class Solution {
public:
    
    // prefix max solution
    int maxArea(vector<int>& arr) {
        int ans=INT_MIN;
        int n=arr.size();
        int l=0,r=n-1;
        while(l<=r){
            // has a bigger line on the right side for the left pointer
            if(arr[l]<arr[r]){
                ans=max(ans,arr[l]*(r-l));
                l++;
            }else{
                ans=max(ans,arr[r]*(r-l));
                r--;
            }
        }
        return ans;
    }
};