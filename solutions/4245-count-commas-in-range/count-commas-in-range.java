class Solution {
    public int countCommas(int n) {
        if(n<1000){
            return 0;
        }else if(n<=100000){
            return (n-1000+1);
        }
        return 0;
    }
}