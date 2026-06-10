class Solution {
public:

    // note: in this question, [1,3],[3,5] => both meetings can be attended

    int minMeetingRooms__sweep(vector<vector<int>>& intervals) {
        int n=intervals.size();
        map<int,int> mp;
        for(auto x: intervals){
            mp[x[0]]++;
            mp[x[1]]--;
        }
        int cnt=0,ans=1;
        for(auto x: mp){
            cnt+=x.second;
            ans=max(ans,cnt);
        }
        return ans;
    }

    // ========== ========== ========== Heap ========== ========== ==========

    int minMeetingRooms__heap(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int cnt=0,ans=1;
        sort(intervals.begin(),intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=pq.top()){
                pq.pop();
                pq.push(intervals[i][1]);
            }else{
                pq.push(intervals[i][1]);
            }
            ans=max(ans,(int)pq.size());
        }
        return ans;
    }

    // ========== ========== ========== 2 pointer ========== ========== ==========

    int minMeetingRooms_2_pointer(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> start;
        vector<int> end;
        for(auto x: intervals){
            start.push_back(x[0]);
            end.push_back(x[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i=0,j=0,ans=0;
        while(i<n && j<n){
            if(start[i]>=end[j]){
                // use the same meeting
                j++;
            }else{
                ans++; // so far max rooms used
            }
            i++;
        }
        return ans;
    }


    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> start;
        vector<int> end;
        for(auto x: intervals){
            start.push_back(x[0]);
            end.push_back(x[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i=0,j=0,ans=0;
        int used=0; // how many rooms currently going on at this moment 
        while(i<n && j<n){
            if(start[i]>=end[j]){
                // use the same meeting
                used--;
                j++;
            }else{
                used++;
                i++;
            }
            ans=max(ans,used);
        }
        return ans;
    }
};