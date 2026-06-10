class Solution {
public:
    int findTheLongestSubstring(string s) {
        string vowels="aeiou";
        int n=s.length(),pre_mask=0,ans=0;
        unordered_map<int,int> mask_odd_idx;
        mask_odd_idx[0]=-1;
        for(int i=0;i<n;i++){
            if(vowels.find(s[i])!=string::npos){
                pre_mask^=(1<<(s[i]-'a'));
            }
            if(mask_odd_idx.count(pre_mask)){
                ans=max(ans,i-mask_odd_idx[pre_mask]);
            }else{
                mask_odd_idx[pre_mask]=i;
            }
        }
        return ans;
    }
};