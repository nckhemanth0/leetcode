class Solution {
public:

    /*
        other way: dp - considering (inde,seats_so_far_before_curr_index) state since
            in SSP => we can go to index 2 either by closing or growing:
                Don’t close yet (keep growing): you arrive at i=2 with seats = 2
                Close right after the second S: you arrive at i=2 with seats = 0 (new section started)

        confirmation of overlapping sub problems: Can two different earlier choices lead to same (i, seats)?
    */

    int numberOfWays__1(string corridor) {
        int cnt=0,n=corridor.size();
        for(int i=0;i<n;i++){
            if(corridor[i]=='S'){
                cnt++;
            }
        }
        if(cnt%2==1 || cnt==0){
            return 0;
        }
        int MOD=1e9+7;
        int l=0;
        long long ans=1;
        while(l<n){
            int x=0, r=l, last_s=l;
            while(x<2 || (x==2 && corridor[r]=='P')){
                // cout<<r<<endl;
                int prev=x;
                if(corridor[r]=='S'){
                    x++;
                }
                if(prev==1 && x==2){
                    last_s=r;
                }
                r++;
            }
            if(r!=n){
                ans=(ans%MOD*(r-last_s)%MOD)%MOD;
            }
            // cout<<l<<" "<<r<<" "<<last_s<<endl;
            l=r;
        }
        return ans;
    }


    // ======== ======== ======== ======== ========

    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;

        long count = 1;
        int seats = 0;
        int previousPairLast = -1;

        for (int index = 0; index < corridor.length(); index++) {
            if (corridor[index] == 'S') {
                seats += 1;
                if (seats == 2) {
                    previousPairLast = index;
                    seats = 0;
                }
                else if (seats == 1 && previousPairLast != -1) {
                    count *= (index - previousPairLast);
                    count %= MOD;
                }
            }
        }

        if (seats == 1 || previousPairLast == -1) {
            return 0;
        }

        return (int) count;
    }
};

/*
    ststtssttss
    ssss
*/