class Solution {
public:

    int n;
    bool rec(int level, vector<int>& bits){
        if(level==-1){
            return true;
        }
        int ans=0;
        if(bits[level]==0){
            if(level-1>=0 && bits[level-1]==1){
                ans|=rec(level-2,bits);
            }
            ans|=rec(level-1,bits);
        }
        if(bits[level]==1){
            if(level-1>=0 && bits[level-1]==1){
                ans|=rec(level-2,bits);
            }
        }
        return -ans;
    }

    bool isOneBitCharacter__rec(vector<int>& bits) {
        n=bits.size();
        if(bits[n-1]!=0){
            return false;
        }
        return rec(n-2,bits);
    }

    // ======== ========= ========

    bool isOneBitCharacter(vector<int>& bits) {
        n=bits.size();
        int i=0,last_ans=0;
        while(i<n){
            if(bits[i]==0){
                i++;
                last_ans=1;
            }else{
                i+=2;
                last_ans=0;
            }
        }
        return last_ans;
    }
};