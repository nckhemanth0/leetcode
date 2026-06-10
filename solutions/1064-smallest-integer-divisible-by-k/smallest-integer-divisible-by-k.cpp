class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0){
            return -1;
        }
        int n=1,cnt=1;
        while(1){
            if(n%k==0){
                return cnt;
            }
            n=((n*10)%k+1)%k;
            cnt++;
        }
        return -1;
    }



/*

                Now, the only problem is how to check whether the required number N exists.

                Notice that if N does not exist, this while loop will continue endlessly. However, the possible values of remainder are limited -- ranging from 0 to K-1. Therefore, if the while-loop continues forever, the remainder repeats. Also, if remainder repeats, then it gets into a loop. Hence, the while-loop is endless if and only if the remainder repeats.

                In this case, we can check if the remainder repeats to check if the while-loop is endless:

                remainder = 1
                length_N = 1

                seen_remainders = set()

                while remainder%K != 0
                    N = remainder*10 + 1
                    remainder = N%K
                    length_N += 1

                    if remainder in seen_remainders
                        return -1
                    else
                        seen_remainders.add(remainder)

                return length_N
                Now we have an algorithm that can solve the problem.

                Furthermore, we can improve this algorithm with Pigeonhole Principle. Recall that the number of possible values of remainder (ranging from 0 to K-1) is limited, and in fact, the number is K. As a result, if the while-loop continues more than K times, and hasn't stopped, then we can conclude that remainder repeats -- you can not have more than K different remainder.

                Hence, if N exists, the while-loop must return length_N in the first K loops. Otherwise, it goes into an infinite loop.

                Therefore, we can just run the while-loop K times, and return -1 if not stopped.





                public int smallestRepunitDivByK(int K) {
                    int remainder = 0;
                    for (int length_N = 1; length_N <= K; length_N++) {
                        remainder = (remainder * 10 + 1) % K;
                        if (remainder == 0) {
                            return length_N;
                        }
                    }
                    return -1;
                }      

*/



};
