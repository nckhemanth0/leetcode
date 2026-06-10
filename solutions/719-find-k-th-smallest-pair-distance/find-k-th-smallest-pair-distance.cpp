class Solution {
public:
    #define ll long long
    vector<ll> arr;
    ll n;

    // (# elements with diff <= mid) >= k
    ll check(ll mid, int k){
        ll cnt=0;
        for(ll i=0;i<n;i++){
            cnt+=(upper_bound(arr.begin(),arr.end(),mid+arr[i])-arr.begin())-(i+1); // # elements after i [so pairs dont get repeated], when paired with i gives difference <= mid
        }
        return cnt>=k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        for(ll i=0;i<n;i++){
            arr.push_back(nums[i]);
        }
        ll lo=0,hi=1e6,ans=hi+1;
        while(lo<=hi){
            ll mid=lo+(hi-lo)/2;
            if(check(mid,k)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};