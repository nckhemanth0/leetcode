class Solution {
public:

    int rev(int &x){
        string v=to_string(x);
        int idx=0;
        for(int i=0;i<v.size();i++){
            if(v[i]!='0'){
                idx=i;
                break;
            }
        }
        int num=0;
        for(int i=v.size()-1;i>=idx;i--){
            num=num*10+(v[i]-'0');
        }
        return num;
    }
    
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<string,int> mp;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            string x=to_string(nums[i]);
            if(mp.count(x)!=0){
                int idx=mp[x];
                ans=min(ans,abs(i-idx));
            }
            mp[to_string(rev(nums[i]))]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};