class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> q;
        for(int i=0;i<n;i++){
            q.push({ratings[i],i});
        }
        int ans=0;
        vector<int> cnt(n,0);
        while(!q.empty()){
            int index=q.top().second;
            q.pop();
            int val=1;
            if(index-1>=0){
                if(cnt[index-1]!=0 && ratings[index]>ratings[index-1]){
                    val=max(val,cnt[index-1]+1);
                }
            }
            if(index<=n-2){
                if(cnt[index+1]!=0 && ratings[index]>ratings[index+1]){
                    val=max(val,cnt[index+1]+1);
                }
            }
            cnt[index]=val;
            ans+=val;
        }
        return ans;
    }
};