class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1){
            return 1;
        }
        int prev=-1; // 0-inc, 1-dec
        int ans=0,cnt=0;
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                cnt=(prev==1)?cnt+1:1;
                prev=0;
            }else if(arr[i-1]>arr[i]){
                cnt=(prev==0)?cnt+1:1;
                prev=1;
            }else{
                cnt=0,prev=-1;
            }
            ans=max(ans,cnt);
        }
        return ans+1;
    }
};