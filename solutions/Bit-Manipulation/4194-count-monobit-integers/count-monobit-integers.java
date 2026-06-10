class Solution {

    public boolean fun(int x){
        int n=x;
        int prev=n&1;
        n=n>>1;
        while(n!=0){
            if(prev!=(n&1)){
                return false;
            }
            n=n>>1;
        }
        return true;
    }
    public int countMonobit(int n) {
        int cnt=0;
        for(int i=0;i<=n;i++){
            if(fun(i)==true){
                cnt++;
            }
        }
        return cnt;
    }
}