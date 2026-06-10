class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        for(auto x: bills){
            if(x==5){
                mp[x]++;
            }else if(x==10){
                if(mp[5]>=1){
                    mp[5]--;
                    mp[10]++;
                }else{
                    return false;
                }
            }else if(x==20){
                if(mp[10]>=1 && mp[5]>=1){
                    mp[10]--;
                    mp[5]--;
                    mp[20]++;
                }else if(mp[5]>=3){
                    mp[5]-=3;
                    mp[20]++;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};