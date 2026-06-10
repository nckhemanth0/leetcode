class Solution {
public:
    int hammingWeight(int n) {
        int sum=0;
        while(n!=0){
            sum++;
            n=n&(n-1);
        }
        return sum;
    }
    int hammingWeight_mask(int n) {
        int mask=1,sum=0;
        for(int i=0;i<32;i++){
            if(n&mask){
                sum++;
            }
            mask<<=1;
        }
        return sum;
    }
};