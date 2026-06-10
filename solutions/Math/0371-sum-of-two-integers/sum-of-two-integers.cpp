class Solution {
public:
    int getSum(int a,int b){
        while(b!=0){
            int temp=(a&b)<<1; // 01100
            a=a^b;          // 00011
            b=temp;
        }
        return a;
    }

    int getSum_wrong_only_for_both_negative(int a, int b) {
        // 12,15
        // 01100
        // 01111
        // 10011
        if(a>b){
            swap(a,b);
        }
        int sum=0,cnt=0,carry=0;
        // make sure a is <= b
        while(a!=0){
            int bit_sum=(a%2+b%2+carry);
            sum+=(bit_sum%2)*pow(2,cnt);
            carry=bit_sum/2;
            cnt++;
            a/=2;
            b/=2;
        }
        while(b!=0){
            int bit_sum=(b%2+carry);
            sum+=(bit_sum%2)*pow(2,cnt);
            carry=bit_sum/2;
            cnt++;
            b/=2;
        }
        if(carry){
            sum+=(pow(2,cnt));
        }
        return sum;
    }
};