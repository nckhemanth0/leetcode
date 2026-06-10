class Solution {
public:

    /*
        other method: sort and loop
    */

    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long ans=0,cnt=0;
        for(int i=0;i<k;i++){
            ans+=max(0LL,(happiness[i]-cnt));
            cnt++;
        }
        return ans;
    }

    // ======== ========== ============ =========

    long long maximumHappinessSum__1(vector<int>& happiness, int k) {
        int n=happiness.size();
        priority_queue<int,vector<int>,greater<>> pq;
        for(int i=0;i<n;i++){
            pq.push(happiness[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        long long ans=0,cnt=k-1;
        while(!pq.empty()){
            ans+=max(0LL,(pq.top()-cnt));
            pq.pop();
            cnt--;
        }
        return ans;
    }
};


/*
    max1-0
    max2-1
    max3-2
    max4-3
    ..
    maxk-(k-1)
*/