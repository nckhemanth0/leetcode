class Solution {
public:
    vector<double> arr={0,1e3,1e6,1e9,1e12,1e15};
    vector<double> val={0,1,2,3,4,5};
    long long countCommas(long long n) {
        if(n<arr[0]){
            return 0;
        }
        auto idx=lower_bound(arr.begin(),arr.end(),n)-arr.begin();
        long long ans=0;
        for(int i=idx;i>=0;i--){
            if(n>=arr[i]){
                ans+=(n-arr[i]+1)*val[i];
                n=arr[i]-1;
            }
        }
        return ans;
    }
};