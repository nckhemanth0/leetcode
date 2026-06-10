class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int> nextOne(n+1,1e9);
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1){
                nextOne[i]=i;
            }else{
                nextOne[i]=nextOne[i+1];
            }
        }
        int lastOne=-1e9,ans=0;
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                lastOne=i;
            }else{
                ans=max(ans,min(i-lastOne,nextOne[i]-i));
            }
        }
        return ans;
    }
};