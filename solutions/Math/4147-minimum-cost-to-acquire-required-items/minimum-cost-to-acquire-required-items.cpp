class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long alone=1LL*cost1*need1+1LL*cost2*need2;
        long long mix=1LL*max(need1,need2)*costBoth;
        long long alonemix1=1LL*costBoth*need1+cost2*(max(0LL,1LL*need2-need1));
        long long mixalone1=1LL*costBoth*need2+cost1*(max(0LL,1LL*need1-need2));
        long long alonemix2=1LL*cost1*need1+costBoth*(max(0LL,1LL*need2));
        long long mixalone2=1LL*cost2*need2+costBoth*(max(0LL,1LL*need1));
        return min({alone,mix,alonemix1,mixalone1,alonemix2,1LL*mixalone2});
    }
};