class Solution {
public:


    /*
        count[i] = count[i - 1] + (nums[i - 1] % modulo == k ? 1 : 0) for i = 1, 2, ..., n
        (count[i] - count[j]) % modulo == k
        count[j] = (count[i] + modulo - k) % modulo
    */

    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long n=nums.size();
        unordered_map<int,int> cnt_idx;
        cnt_idx[0]=1;
        long long cnt=0,ans=0;
        for(int i=0;i<n;i++){
            cnt=(cnt+(nums[i]%modulo==k)+modulo)%modulo;
            long long req_cnt=(cnt-k+modulo)%modulo;
            if(cnt_idx.count(req_cnt)){
                ans+=cnt_idx[req_cnt];
            }
            cnt_idx[cnt]++;
        }
        return ans;
    }
};