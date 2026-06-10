class Solution {
public:
    using ll=long long;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int sz=meetings.size();
        sort(meetings.begin(),meetings.end());
        vector<vector<ll>> end_times(n,vector<ll>(1,-1));

        ll wait_time=0;
        for(int i=0;i<sz;i++){
            bool found=false;
            ll min_end_time=LLONG_MAX;
            for(int j=0;j<n;j++){
                min_end_time=min(min_end_time,end_times[j].back());
                if(wait_time+meetings[i][0]>=end_times[j].back()){
                    end_times[j].push_back(wait_time+meetings[i][1]);
                    wait_time=0;
                    found=true;
                    break;
                }
            }
            if(!found){
                wait_time=min_end_time-meetings[i][0];
                i--;
            }
        }

        ll maxi=LLONG_MIN, maxi_index=-1;
        for(int i=0;i<n;i++){
            int size=end_times[i].size();
            if(maxi<size){
                maxi=size;
                maxi_index=i;
            }
        }
        return maxi_index;
    }

};

/*
    debugging:
    
        for(auto x: meetings){
            cout<<x[0]<<" "<<x[1]<<endl;
        }

        for(int i=0;i<n;i++){
            cout<<i<<" : ";
            for(auto y: end_times[i]){
                cout<<y<<" ";
            }
            cout<<endl;
        }
*/