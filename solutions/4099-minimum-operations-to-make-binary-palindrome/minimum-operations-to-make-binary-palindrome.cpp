class Solution {
public:
    bool isPalindrome(int x){
        if(x==1){
            return true;
        }
        int left=(int)log2((double)x);
        int right=0;
        while(left>right){
            int left_set=(x&(1 << left))!=0;
            int right_set=(x&(1 << right))!=0;
            if(left_set!=right_set){
                return false;
            }
            left--;
            right++;
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int diff=0;
            while(1){
                if(isPalindrome(nums[i]+diff) || isPalindrome(nums[i]-diff)){
                    break;
                }
                diff++;
            }
            ans.push_back(diff);
        }
        return ans;
    }
};