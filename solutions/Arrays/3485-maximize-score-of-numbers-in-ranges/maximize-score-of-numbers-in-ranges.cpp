class Solution {
public:
    #define ll long long
    vector<ll> st;
    ll n;
    // check if we can choose points in ranges such that atleast mid (min absolute distance) distance can be maintained b/w points
    ll check(ll mid, int d){
        ll prev=st[0];
        for(ll i=1;i<n;i++){
            ll nxt=max(prev+mid,st[i]);
            if(nxt>st[i]+d){
                return false;
            }
            prev=nxt;
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        n=start.size();
        for(ll i=0;i<n;i++){
            st.push_back(start[i]);
        }
        sort(st.begin(),st.end());
        int lo=0,hi=(st[n-1]-st[0]+d),ans=hi+1;
        while(lo<=hi){
            ll mid=lo+(hi-lo)/2;
            if(check(mid,d)){
                lo=mid+1;
                ans=mid;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
};