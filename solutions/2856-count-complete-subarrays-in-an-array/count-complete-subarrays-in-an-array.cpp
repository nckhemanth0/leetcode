class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int tail=0,head=-1,n=nums.size(),dist=0,total_dist=0,ans=0;
        unordered_map<int,int> mp;
        for(auto x: nums){
            if(mp[x]==0){
                total_dist++;
            }
            mp[x]++;
        }
        mp.clear();
        while(tail<n){
            while((head+1<n) && dist<total_dist){
                head++;
                if(mp[nums[head]]==0){
                    dist++;
                }
                mp[nums[head]]++;
            }
            if(dist==total_dist){
                ans+=(n-head);
            }
            if(head<tail){
                head=tail-1;
                dist=0;
            }else{
                mp[nums[tail]]--;
                if(mp[nums[tail]]==0){
                    dist--;
                }
            }
            tail++;
        }
        return ans;
    }
};