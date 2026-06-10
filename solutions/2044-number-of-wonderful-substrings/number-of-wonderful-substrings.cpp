class Solution {
public:
    // jihgfedcba
    long long wonderfulSubstrings(string word) {
        int n=word.size();
        long long pre_mask=0,ans=0;
        unordered_map<long long,int> mask_odd_cnt;
        mask_odd_cnt[0]=1;
        for(int i=0;i<n;i++){
            pre_mask^=(1<<(word[i]-'a'));
            ans+=mask_odd_cnt[pre_mask];
            for(int k=0;k<10;k++){
                ans+=mask_odd_cnt[pre_mask^(1<<k)];
            }
            mask_odd_cnt[pre_mask]++;
        }
        return ans;
    }
};

/*
    aab|bb|a
       1  3

    10 => 10
    (1,2) => (3,2)
*/