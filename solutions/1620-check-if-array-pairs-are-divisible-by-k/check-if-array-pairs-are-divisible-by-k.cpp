class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mod_cnt;
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int mod=((arr[i]%k)+k)%k;
            int req_mod=(k-mod)%k;
            if(mod_cnt.count(req_mod)){
                mod_cnt[req_mod]--;
                if(mod_cnt[req_mod]==0){
                    mod_cnt.erase(req_mod);
                }
            }else{
                mod_cnt[mod]++;
            }
        }
        for(auto x: mod_cnt){
            if(x.second!=0){
                return false;
            }
        }
        return true;
    }
};