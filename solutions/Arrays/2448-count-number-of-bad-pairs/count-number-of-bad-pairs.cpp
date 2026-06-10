class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        unordered_map<long long,int> diff_cnt;
        long long not_ans=0;
        for(int i=0;i<n;i++){
            long long diff=nums[i]-i;
            if(diff_cnt.count(diff)){
                not_ans+=diff_cnt[diff];
            }
            diff_cnt[diff]++;
        }
        return n*(n-1)/2 - not_ans;
    }

    long long countBadPairs__(vector<int>& nums) {
        long long badPairs = 0;
        unordered_map<int, int> diffCount;

        for (int pos = 0; pos < nums.size(); pos++) {
            int diff = pos - nums[pos];

            int goodPairsCount = diffCount[diff];
            badPairs += pos - goodPairsCount;
            
            diffCount[diff] = goodPairsCount + 1;
        }

        return badPairs;
    }
};