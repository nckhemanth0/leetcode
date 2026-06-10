class Solution {
public:

    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=0,ans=0;
        while(i<n && j<n){
            if(i==j){
                j++;
                continue;
            }
            if(nums[j]-nums[i]>k){
                i++;
            }else if(nums[j]-nums[i]<k){
                j++;
            }else{
                ans++;
                int x=nums[j];
                while(j<n && nums[j]==x){
                    j++;
                }
            }
        }
        return ans;
    }

    int findPairs_(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_set<int> s;
        s.insert(nums[0]);
        int ans=0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                while(i+1<n && nums[i]==nums[i+1]){
                    i++;
                }
                if(k==0){
                    ans++;
                }
                continue;
            }
            if(s.find(nums[i]-k)!=s.end()){
                ans++;
            }
            s.insert(nums[i]);
        }
        return ans;
    }
};