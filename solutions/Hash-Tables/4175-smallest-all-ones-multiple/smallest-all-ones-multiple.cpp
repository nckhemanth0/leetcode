class Solution {
public:
    int minAllOneMultiple(int k) {
        int x=1;
        int len=1;
        unordered_map<int,int> mp;
        while(1){
            int rem=x%k;
            if(mp.count(rem)){
                return -1;
            }
            if(rem==0){
                return len;
            }
            mp[rem]=1;
            x=((x*10)%k+1)%k;
            len++;
        }
        return -1;
    }
};