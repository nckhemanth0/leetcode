class Solution1 {
public:
    // are there k subsets consuming all numbers with where each subset sum is target
    int n,main_target;
    vector<int> vis;
    int cnt=0;
    bool rec(int level, int target, int k, vector<int> &nums){
        if(k==1){
            return true;
        }
        if(target==0){
            return rec(0,main_target,k-1,nums);
        }
        if(target<0 || level==n){
            return false;
        }
        for(int i=level;i<n;i++){ // permutations do not matter so we can use level
            if(!vis[i]){
                vis[i]=1;
                if(rec(i+1,target-nums[i],k,nums)){
                    return true;
                }
                vis[i]=0;
                if(target==main_target){ 
                    return false;
                }
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        n=nums.size();
        for(auto x: nums){
            sum+=x;
        }
        if((sum%k)!=0){
            return false;
        }
        vis.resize(n,0);
        main_target=(sum/k);
        return rec(0,main_target,k,nums);
    }
};

class Solution {
public:
    int n, K, main_target;
    vector<int> nums;
    unordered_map<long long, int> memo;

    long long makeKey(int level, int target, int k, int mask) {
        long long key = mask;
        key = key * (n + 1) + level;
        key = key * (main_target + 1) + target;
        key = key * (K + 1) + k;
        return key;
    }

    bool rec(int level, int target, int k, int mask) {
        if(k == 1) return true;

        if(target == 0)
            return rec(0, main_target, k - 1, mask);   // seal bucket, restart scan

        if(level == n) return false;

        long long key = makeKey(level, target, k, mask);
        if(memo.count(key)) return memo[key];

        // take nums[level] into this bucket
        if(!(mask & (1 << level)) && nums[level] <= target) {
            if(rec(level + 1, target - nums[level], k, mask | (1 << level)))
                return memo[key] = 1;
        }

        // skip nums[level] only for THIS bucket scan
        if(rec(level + 1, target, k, mask))
            return memo[key] = 1;

        return memo[key] = 0;
    }

    bool canPartitionKSubsets(vector<int>& a, int k) {
        nums = a;
        K = k;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;

        main_target = sum / k;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] > main_target) return false;

        n = nums.size();
        return rec(0, main_target, k, 0);
    }
};