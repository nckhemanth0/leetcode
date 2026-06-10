class Solution {
public:
    int rec(int &x){
        int ans=0,cnt=0;
        for(int d=1;d*d<=x;d++){
            if(x%d==0){
                if(d*d!=x){
                    ans+=(x/d)+d;
                    cnt+=2;
                }else{
                    ans+=d;
                    cnt++;
                }
            }
        }
        return (cnt==4?ans:0);
    }
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=rec(nums[i]);
        }
        return ans;
    }
};