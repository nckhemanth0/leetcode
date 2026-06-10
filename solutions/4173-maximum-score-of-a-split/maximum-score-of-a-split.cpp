class Solution {
public:
    using ll=long long;
    long long maximumScore(vector<int>& nums) {
        ll n=nums.size();
        vector<ll> pre(n,0);
        vector<ll> suf(n,LLONG_MAX);
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        ll ans=LLONG_MIN;
        for(int i=0;i<n;i++){
            pre[i]+=((i-1>=0)?pre[i-1]:0)+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=min(suf[i+1],1LL*nums[i+1]);
            ans=max(ans,pre[i]-suf[i]);
        }
        return ans;
    }
};