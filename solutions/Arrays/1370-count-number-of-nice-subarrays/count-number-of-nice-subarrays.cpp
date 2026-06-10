class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int odd_cnt=0;
        unordered_map<int,int> pre_odds;
        pre_odds[0]=1; // count 0 is till -1 index
        // for(int i=0;i<n;i++){

        //     if(nums[i]&1){
        //         pre_odds[i+1]=pre_odds[i]+1;
        //     }else{
        //         pre_odds[i+1]=pre_odds[i];
        //     }
        // }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                odd_cnt++;
            }
            if(pre_odds.count(odd_cnt-k)){
                // pre_odds[odd_cnt-k] => num of times we got odd count = odd_cnt-k
                ans+=pre_odds[odd_cnt-k];
            }
            pre_odds[odd_cnt]++;
        }
        return ans;
    }
};