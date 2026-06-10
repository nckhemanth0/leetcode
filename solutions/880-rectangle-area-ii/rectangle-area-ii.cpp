class Solution {
public:
    using ll=long long;
    ll MOD=1e9+7;
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<vector<int>> events;
        for(auto x: rectangles){
            events.push_back({x[0],1,x[1],x[3]});
            events.push_back({x[2],0,x[1],x[3]});
        }
        sort(events.begin(),events.end());
        int n=events.size();
        multiset<pair<int,int>> ms;
        int i=0;
        ll ans=0;
        int prev=0;
        while(i<n){
            // cout<<events[i][0]<<" "<<events[i].o<<" "<<events[i].h<<" "<<events[i].other<<endl;
            if(!ms.empty()){
                ll width=(events[i][0]-prev+MOD)%MOD;
                ll prev_lo,prev_hi;
                bool first=true;
                for(auto [lo,hi]: ms){
                    if(first){
                        prev_lo=lo;
                        prev_hi=hi;
                        first=false;
                    }
                    else if(lo>=prev_hi){
                        ans+=(prev_hi-prev_lo)%MOD*(width)%MOD;
                    ans%=MOD;
                        prev_lo=lo;
                        prev_hi=hi;
                    }else{
                        prev_hi=max(1LL*hi,prev_hi);
                    }
                }
                ans+=(prev_hi-prev_lo)%MOD*(width)%MOD;
                ans%=MOD;
            }
            auto x=events[i][0];
            prev=x;
            do{
                if(events[i][1]==1){
                    ms.insert({events[i][2],events[i][3]});
                }else{
                    ms.erase(ms.find({events[i][2],events[i][3]}));
                }
                i++;
            } while(i<n && events[i][0]==x);
        }
        return ans;

    }
};