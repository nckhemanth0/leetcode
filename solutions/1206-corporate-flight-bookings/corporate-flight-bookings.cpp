class Solution {
public:
    // just partial sums but chnages indices a bit due to ans format
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n,0);
        for(auto x: bookings){
            v[x[0]-1]+=x[2];
            if(x[1]<n) v[x[1]]-=x[2];
        }
        for(int i=1;i<=n-1;i++){
            v[i]+=v[i-1];
        }
        return v;
    }
};