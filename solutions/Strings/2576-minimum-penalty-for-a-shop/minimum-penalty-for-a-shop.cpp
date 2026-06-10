class Solution {
public:

    // For convenience, we can directly set cur_penalty to 0, which is equivalent to shifting the curve of the actual penalty vertically. This will not affect the calculation result. Note that we could initialize cur_penalty to any value and the algorithm would still work since the initial reference point is insignificant.
    // see graph

    int bestClosingTime__single_pass(string customers) {
        int minPenalty = 0, curPenalty = 0;
        int earliestHour = 0;
        for (int i = 0; i < customers.size(); i++) {
            char ch = customers[i];
            if (ch == 'Y') {
                curPenalty--;
            } else {
                curPenalty++;
            }
            if (curPenalty < minPenalty) {
                earliestHour = i + 1;
                minPenalty = curPenalty;
            }
        }
        return earliestHour;
    }

    // ======= ======== =========== ======== =======

    int bestClosingTime(string customers) {
        int Y=0;
        int n=customers.size();
        for(int i=0;i<n;i++){
            Y+=(customers[i]=='Y');
        }
        int N=0;
        int i=0,mini=INT_MAX, minindex=-1;
        for(;i<=n;i++){
            int x=N+Y;
            if(mini>x){
                mini=x;
                minindex=i;
            }
            if(i<n){
                customers[i]=='Y'?Y--:N++;
            }
        }
        // if(mini>N){
        //     mini=N;
        //     minindex=n;
        // }
        return minindex;
    }

    // ======= ======== =========== ======== =======

    int bestClosingTime__seperator_logic_postorder(string customers) {
        int curPenalty = 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (customers[i] == 'Y') {
                curPenalty++;
            }
        }
        int minPenalty = curPenalty;
        int earliestHour = 0;
        for (int i = 0; i < customers.size(); ++i) {
            char ch = customers[i];
            if (ch == 'Y') {
                curPenalty--;
            } else {
                curPenalty++;
            }
            if (curPenalty < minPenalty) {
                earliestHour = i + 1;
                minPenalty = curPenalty;
            }
        }
        return earliestHour;
    }
};

/*
   ------------)[------------
     cnt of N      cnt of Y
*/


