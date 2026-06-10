// class Solution {
// public:

//     int rec(int level,int cnt,vector<int>& costs, vector<int>& capacity, int budget){
//         if(cnt>=3 || budge<0){
//             return INT_MIN;
//         }
//         if(level==n){
//             if(budget>0){
//                 return 0;
//             }
//             return INT_MIN;
//         }
//     }
//     int check(int mid,int cnt,vector<int>& costs, vector<int>& capacity, int budget){
//         if(cnt>=3 || budge<0){
//             return INT_MIN;
//         }
//         if(level==n){
//             if(budget>0){
//                 return 0;
//             }
//             return INT_MIN;
//         }
//     }
//     int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
//         int n=costs.size();
//         rec(0,0,costs,capacity,budget);

//         int lo=0, hi=2e5+1,ans=0;
//         while(lo<=hi){
//             int mid=lo+((hi-lo)>>1);
//             if(check(mid,costs,capacity,budget)){
//                 ans=mid;
//                 lo=mid+1;
//             }else{
//                 hi=mid-1;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:

    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n=costs.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({costs[i],capacity[i]});
        }
        sort(v.begin(),v.end());
        // int i=0,j=n-1;
        int ans=0;
        // while(i<=j){
        //     if(cost[i]<budget){
        //         ans=max(ans,capacity[i]);
        //     }
        //     if(cost[j]<budget){
        //         ans=max(ans,capacity[j]);
        //     }
        //     if(cost[i]+cost[j]>=budget){
        //         j--;
        //     }else{
        //         ans=max(ans,capacity[i]+capacity[j]);
                
        //     }
               
        // }
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            if(v[i].first<budget){
                ans=max(ans,v[i].second);
            }
            pre[i+1]=max(pre[i],v[i].second);
        }
        for(int j=1;j<n;j++){
            auto mp=make_pair(budget-v[j].first,INT_MIN);
            auto it=lower_bound(v.begin(),v.begin()+j,mp);
            int idx=it-v.begin();
            if(idx==0){
                continue;
            }
            idx--;
            ans=max(ans,pre[idx+1]+v[j].second);
        }
        return ans;
    }
};

// c[i]+c[j]<budget
// 3,4,5,8
// 7,1,2,5