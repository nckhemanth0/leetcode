class Solution {
public:

    // note: in this question, [1,3],[3,5] => both meetings can be attended

    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n=intervals.size();
        map<int,int> mp;
        for(auto x: intervals){
            mp[x[0]]++;
            mp[x[1]]--;
        }
        int cnt=0;
        for(auto x: mp){
            cnt+=x.second;
            if(cnt>=2){
                return false;
            }
        }
        return true;
    }
};