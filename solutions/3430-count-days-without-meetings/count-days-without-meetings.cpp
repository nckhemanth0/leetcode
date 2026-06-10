class Solution {
public:
    int countDays__sweep(int days, vector<vector<int>>& meetings) {
        map<int,int> mp;
        for(auto x: meetings){
            mp[x[0]]++;
            mp[x[1]+1]--;
        }
        int ans=0, cnt=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            cnt+=it->second;
            auto next_itr=next(it);
            if(next_itr!=mp.end() && cnt!=0){
                ans+=next_itr->first-it->first;
            }
        }
        return days-ans;
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());
        int lastend=meetings[0][1];
        int start=meetings[0][0];
        int ans=0;
        for(int i=1;i<n;i++){
            if(meetings[i][0]>lastend+1){
                ans+=(lastend-start+1);
                start=meetings[i][0];
            }
            lastend=max(lastend,meetings[i][1]);
        }
        ans+=lastend-start+1;
        return days-ans;
    }
};