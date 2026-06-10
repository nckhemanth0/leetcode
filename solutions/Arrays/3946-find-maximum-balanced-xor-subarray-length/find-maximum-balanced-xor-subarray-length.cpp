class Solution {
public:

    int maxBalancedSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,unordered_map<int,int>> xor_idx;
        int pre_xor=0,ans=0,evens_minus_odds=0;
        xor_idx[0][0]=-1;
        for(int i=0;i<n;i++){
            evens_minus_odds=evens_minus_odds+(nums[i]%2==0)-(nums[i]%2==1);
            pre_xor^=(nums[i]);
            if(xor_idx.count(pre_xor) && xor_idx[pre_xor].count(evens_minus_odds)){
                int idx=xor_idx[pre_xor][evens_minus_odds];
                ans=max(ans,i-idx);
            }else{
                xor_idx[pre_xor][evens_minus_odds]=i;
            }
        }
        return ans;
    }

    int maxBalancedSubarray__2d_prefix(vector<int>& nums) {
        vector<int> evens_minus_odds;
        int n=nums.size();
        evens_minus_odds.assign(n+1,0);
        unordered_map<int,unordered_map<int,int>> xor_idx;
        int pre_xor=0,ans=0;
        xor_idx[0][0]=-1;
        for(int i=0;i<n;i++){
            evens_minus_odds[i+1]=evens_minus_odds[i]+(nums[i]%2==0)-(nums[i]%2==1);
            pre_xor^=(nums[i]);
            if(xor_idx.count(pre_xor) && xor_idx[pre_xor].count(evens_minus_odds[i+1])){
                int idx=xor_idx[pre_xor][evens_minus_odds[i+1]];
                if((evens_minus_odds[i+1]-evens_minus_odds[idx+1])==0){
                    ans=max(ans,i-idx);
                }
            }else{
                xor_idx[pre_xor][evens_minus_odds[i+1]]=i;
            }
        }
        return ans;
    }

    /*
                Tiny optimisation (without changing the idea)

                You can compress the (pre_xor, evens_minus_odds) pair into a single key so you have one map instead of map-of-map, e.g.:

                unordered_map<long long,int> first;   // state -> earliest index
                auto key = [&](int x, int d) {
                    // pack (xor, diff) into one 64-bit key
                    return ( (long long)x << 32 ) ^ (unsigned int)d;
                };

                Then:

                first[key(0,0)] = -1;
                ...
                int x = pre_xor;
                int d = evens_minus_odds[i+1];
                auto k = key(x,d);

                if (first.count(k)) {
                    ans = max(ans, i - first[k]);
                } else {
                    first[k] = i;
                }

                Still O(n) time, O(n) space.

                No need for the extra check
                if ((evens_minus_odds[i+1] - evens_minus_odds[idx+1]) == 0)
                because the key already encodes that equality.
    */

};










/*
class Solution {
public:
    vector<int> evens;
    vector<int> odds;
    vector<vector<int>> dp;

    int rec(int i, int j, vector<int>& nums, int x) {
        if (i > j) return 0;

        int &res = dp[i][j];
        if (res != -1) return res;

        int Ev = evens[j+1] - evens[i];
        int Od = odds[j+1]  - odds[i];

        if (Ev == Od && x == 0) {
            return res = j - i + 1;
        }

        int best = 0;
        best = max(best, rec(i + 1, j, nums, x ^ nums[i]));
        best = max(best, rec(i, j - 1, nums, x ^ nums[j]));

        return res = best;
    }

    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        evens.assign(n + 1, 0);
        odds.assign(n + 1, 0);
        dp.assign(n, vector<int>(n, -1));

        int x = 0;
        for (int i = 0; i < n; i++) {
            evens[i+1] = evens[i] + (nums[i] % 2 == 0);
            odds[i+1]  = odds[i]  + (nums[i] % 2 == 1);
            x ^= nums[i];
        }

        return rec(0, n - 1, nums, x);
    }
};

*/




















/*
class Solution {
public:

    vector<int> evens;
    vector<int> odds;
    
    int rec(int i,int j, vector<int>& nums, int x){
        while(i<=j){
            // cout<<i<<" "<<j<<endl;
            if((evens[j+1]-evens[i])==(odds[j+1]-odds[i]) && x==0){
                return j-i+1;
            }else if((evens[j+1]-evens[i])<(odds[j+1]-odds[i])){
                if(nums[i]%2==1){
                    x^=nums[i];
                    i++;
                }else{
                    x^=nums[j];
                    j--;

                }
            }else if((evens[j+1]-evens[i])>(odds[j+1]-odds[i])){
                if(nums[i]%2==0){
                    x^=nums[i];
                    i++;
                }else{
                    x^=nums[j];
                    j--;
                }
            }else{
                x^=nums[i]^nums[j];
                i++;j--;
            }
        }
        return 0;
    }
    
    int maxBalancedSubarray(vector<int>& nums) {
        int n=nums.size();
        evens.resize(n+1,0);
        odds.resize(n+1,0);
        int x=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                evens[i+1]=evens[i]+1;
            }else{
                evens[i+1]=evens[i];
            }
            if(nums[i]%2==1){
                odds[i+1]=odds[i]+1;
            }else{
                odds[i+1]=odds[i];
            }
            x^=(nums[i]);
        }
        // for(auto x: evens){
        //     cout<<x<<endl;
        // }
        return rec(0,n-1,nums,x);
       
    }
};
*/