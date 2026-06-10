class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n=nums.size();
        int p1=0,p2=0;
        bool active=0;
        for(int i=0;i<n;i++){
            if(i%6==5){
                active=1-active;
            }
            if(nums[i]&1){
                active=1-active;
            }
            if(active==0){
                p1+=nums[i];
            }else{
                p2+=nums[i];
            }
        }
        return p1-p2;
    }
};