class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<int> suffix(n+1,0);
        for(int i=n-1;i>=0;i--){
            suffix[i]=nums[i]+suffix[i+1];
        }
        int prefix=0, ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int diff=abs(prefix-suffix[i+1]);
                if(diff==0){
                    ans+=2;
                }else if(diff==1){
                    ans++;
                }
            }
            prefix+=nums[i];
        }
        return ans;
    }
};