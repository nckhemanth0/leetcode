class Solution {
public:
    using pii=pair<int,int>;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        int MOD=1e9+7;
        priority_queue<pii> buy; // max heap
        priority_queue<pii,vector<pii>,greater<pii>> sell; //min heap
        long long ans=0;
        for(auto order: orders){
            ans+=order[1];
            if(order[2]==0){
                buy.push({order[0],order[1]});
            }else{
                sell.push({order[0],order[1]});
            }
            while(!buy.empty() && !sell.empty() && buy.top().first>=sell.top().first){
                int buyP=buy.top().first, buyA=buy.top().second; buy.pop();
                int sellP=sell.top().first, sellA=sell.top().second; sell.pop();
                int exec=min(buyA, sellA);
                ans-=(2L*exec);
                if(buyA>exec){
                    buy.push({buyP, buyA-exec});
                }
                if(sellA>exec){
                    sell.push({sellP, sellA-exec});
                }
            }
        }
        return ans%MOD;
    }
};