class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        priority_queue<int,vector<int>,greater<>> pq;
        sort(events.begin(),events.end());
        int i=0,day=1,ans=0;
        while(i<n || !pq.empty()){
            // pruning
            if(pq.empty()){
                day=events[i][0];
            }
            // push into pq all meetings whose start day <= day
            while(i<n && events[i][0]==day){
                pq.push({events[i][1]});
                i++;
            }
            // remove all meetings with end_day < day
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
            // this window of pq has all valid events. Pick best!
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
            day++;
        }
        return ans;
    }
};