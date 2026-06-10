class Solution {
public:

    using pii=pair<int,int>;
    #define f first
    #define s second

    int maxTwoEvents(vector<vector<int>>& events) {
        n=events.size();
        vector<pair<int,pair<int,int>>> order; 
        for(int i=0;i<n;i++){
            order.push_back({events[i][0],{1,events[i][2]}});
            order.push_back({events[i][1]+1,{-1,events[i][2]}});
        }
        sort(order.begin(),order.end());
        int max_of_prev_non_overlapping=0; // no element taken initally
        int ans=INT_MIN;
        for(auto x:order){
            if(x.s.f==1){
                ans=max(ans,max_of_prev_non_overlapping+x.s.s);
            }else{
                max_of_prev_non_overlapping=max(max_of_prev_non_overlapping,x.s.s);
            }
        }
        return ans;
    }

    /*
    observations:
    1. min heap by event end time will make sure we pick max value from all events before
    this end time. All other events in heap are overlapping.
    2. 
    */
    int maxTwoEvents_PQ(vector<vector<int>>& events) {
        n=events.size();
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int max_val_till_tops_end=0;
        int ans_sum=INT_MIN;
        for(int i=0;i<events.size();i++){
            while(!pq.empty()){ // top present!
                pair<int,int> x=pq.top(); // till now - pick the min ending time event
                if(x.first<events[i][0]){ // top's end < cur's start
                    // accumulate max till now from all non-overlapping events
                    // such that we merge cur with that later for max sum 
                    max_val_till_tops_end=max(max_val_till_tops_end,x.second);
                    pq.pop();
                }else{ // do not have any event in heap that is non-overlapping
                    break;
                }
            }
            ans_sum=max(ans_sum,max_val_till_tops_end+events[i][2]);
            pq.push({events[i][1],events[i][2]});
        }
        return ans_sum;
    }

   // ============================================================

    int maxTwoEvents_BS_precompute_suffix(vector<vector<int>>& events) {
        sort(events.begin(), events.end());            // sort by start, then end, then value
        int n = (int)events.size();

        // suffix[i] = max value among events[i..n-1]
        vector<int> suffix(n, 0);
        suffix[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = max(suffix[i + 1], events[i][2]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // first event with start >= events[i][1] + 1  (i.e., start > end)
            auto it = lower_bound(events.begin(), events.end(),
                                  vector<int>{events[i][1] + 1, INT_MIN, INT_MIN});

            if (it != events.end()) {
                int j = (int)(it - events.begin());
                ans = max(ans, events[i][2] + suffix[j]);
            } else {
                ans = max(ans, events[i][2]); // take only this event
            }
        }
        return ans;
    }

   // ============================================================

    int n;
    int dp[100001][3];

    int rec(vector<vector<int>>& events,int level,int taken){
        if(taken>=2 || level>=n){
            return 0;
        }
        if(dp[level][taken]!=-1){
            return dp[level][taken];
        }
        int ans=INT_MIN;

        // Binary search manually
        // int lo=level+1,hi=n-1,split=n;
        // while(lo<=hi){
        //     int mid=lo+(hi-lo)/2;
        //     if(events[mid][0]>events[level][1]){
        //         hi=mid-1;
        //         split=mid;
        //     }else{
        //         lo=mid+1;
        //     }
        // }

        // upper_bound(..., {endTime, INT_MAX, INT_MAX})

        // lower_bound(..., {endTime+1, -1, -1})

        int split=upper_bound(events.begin(),events.end(),events[level][1],[](int value,const vector<int> &v){
                                                                return value<v[0];
                                                            })-events.begin();

        ans=max(ans,events[level][2]+rec(events,split,taken+1)); // take

        ans=max(ans,rec(events,level+1,taken)); // not take

        return dp[level][taken]=ans;
    }

    int maxTwoEvents_DP(vector<vector<int>>& events) {
        n=events.size();
        memset(dp,-1,sizeof(dp));
        sort(events.begin(),events.end());
        return rec(events,0,0);
    }


    // ============================================================

    unordered_map<int, unordered_map<int, int>> DP[3];
    vector<vector<int>> events;
    int N;

    int rec_sol1_TLE(int x, int taken, int lastEnd) {
        if (taken == 2 || x >= N) return 0;
        if (DP[taken][x].count(lastEnd)) return DP[taken][x][lastEnd];

        int ans = rec_sol1_TLE(x + 1, taken, lastEnd);

        if (events[x][0] > lastEnd) { 
            ans = max(ans, events[x][2] + rec_sol1_TLE(x + 1, taken + 1, events[x][1]));
        }

        return DP[taken][x][lastEnd] = ans;
    }

    int maxTwoEvents_sol1_TLE(vector<vector<int>>& inputEvents) {
        events = inputEvents;
        N = events.size();
        sort(events.begin(), events.end()); // Sort by start time
        return rec_sol1_TLE(0, 0, -1);
    }
};