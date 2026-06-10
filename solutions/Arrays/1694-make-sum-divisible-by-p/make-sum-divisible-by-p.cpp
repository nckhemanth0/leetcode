class Solution {
public:

    // Other way to think: we need smallest subarray with sum = total_sum-p divisible by p. if not possible or sum==p then -1
    int minSubarray(vector<int>& nums, int p) {
        long long n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int k=sum%p;
        if(k==0){
            return 0;
        }
        unordered_map<int,int> mod_idx;
        mod_idx[0]=-1;
        long long mod_sum=0, ans=n;
        for(int i=0;i<n;i++){
            mod_sum=((mod_sum+nums[i])%p+p)%p;
            int req_mod_sum=((mod_sum-k+p)%p+p)%p;
            if(mod_idx.count(req_mod_sum)){
                ans=min(ans, 1LL*i-mod_idx[req_mod_sum]);
            }
            mod_idx[mod_sum]=i;
        }
        return ans==n?-1:ans;
    }
};

/*

                remaining sum = S - x; We want: (S - x) % p == 0
                (S - x) % p == 0 ⇔ S % p == x % p where let target = S % p
                subarray_sum % p == target
                        prefix[i] = sum(nums[0..i-1])        // sum of first i elements
                        rem[i]    = prefix[i] % p            // remainder of prefix[i]
                        subarray_sum = prefix[r] - prefix[l]
                (prefix[r] - prefix[l]) % p == target
                        https://leetcode.com/problems/subarray-sums-divisible-by-k/ => here target is 0
                (prefix[r] % p - prefix[l] % p + p) % p == target
                rem[r] = prefix[r] % p
                        need rem[l] such that:
                        (rem[r] - rem[l] + p) % p == target
                rem[l] == (rem[r] - target + p) % p
                So we track rem[i] in map and while checking previous l we do map.find((rem[r] - target + p) % p)
                        i.e…Store rem[i] → earliest index in a map; for each r, compute needed = (rem[r] - target + p) % p, and if it exists, update ans = min(ans, r - map[needed]).


*/