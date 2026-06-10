class Solution {
public:
    // 9876543210
    // question in other way: all digits freq count -> 0 or 1 odd
    int longestAwesome(string s) {
        int n=s.length();
        unordered_map<int,int> mask_odd_idx;
        mask_odd_idx[0]=-1;
        int pre_mask=0,ans=0;
        for(int i=0;i<n;i++){
            pre_mask^=(1<<(s[i]-'0'));
            if(mask_odd_idx.count(pre_mask)){
                ans=max(ans,i-mask_odd_idx[pre_mask]);
            }
            for(int k=0;k<10;k++){
                if(mask_odd_idx.count(pre_mask^(1<<k))){
                    ans=max(ans,i-mask_odd_idx[pre_mask^(1<<k)]);
                }
            }
            if(mask_odd_idx.count(pre_mask)==0){
                mask_odd_idx[pre_mask]=i;
            }
        }
        return ans;
    }
};