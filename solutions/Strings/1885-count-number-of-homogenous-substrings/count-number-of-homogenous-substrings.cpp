class Solution {
public:
    const int MOD=1e9+7;
    int countHomogenous(string s) {
        int n=s.length();
        char prev=s[0];
        int cnt=1;
        int ans=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
                cnt=1;
            }
            ans=(ans+cnt)%MOD;
        }
        return ans;
    }

    // ==== === ====== 
    /*
        FOR SLIDING WINDOW APPROACH, KEEP TRACK OF CNT OF DISTINCT. THEN 
        LEFT=0, RIGHT 0 TO N-1
        FOR EVERY RIGHT TRY TO GET VALID SUBSTRING AND ADD LENGTH TO ANSWER
        IF ANY WINDOW SEEMS INVALID(CNT OF DISTICT>1) THEN WE CAN INCREASE LEFT FORWARD
    */
};