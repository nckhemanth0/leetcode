class Solution {
public:

    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0,n=timeSeries.size();
        for(int i=0;i<n-1;i++){
            ans+=min(duration, (timeSeries[i+1]-timeSeries[i]));
        }
        ans+=duration;
        return ans;
    }

    int findPoisonedDuration__sort_unoptimized(vector<int>& timeSeries, int duration) {
        map<int,int> mp;
        for(auto x: timeSeries){
            mp[x]++;
            mp[x+duration-1+1]--;
        }
        for(auto x: mp){
            cout<<x.first<<" "<<x.second<<endl;
        }
        int cnt=0, ans=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            auto next_it=next(it);
            cnt+=it->second;
            if(next_it != mp.end() && cnt!=0){
                ans+=(next_it->first - it->first);
            }
        }
        return ans;
    }
};