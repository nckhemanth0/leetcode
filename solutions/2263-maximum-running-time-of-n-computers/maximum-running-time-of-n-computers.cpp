class Solution {
public:

    bool check(long long mid, int n, vector<int>& batteries){
        long long sum=0;
        for(auto x: batteries){
            sum+=min(1LL*x,mid);
        }
        return sum>=n*mid;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long size=batteries.size();
        if(n>size){
            return 0;
        }
        long long sum=0;
        for(auto x: batteries){
            sum+=x;
        }
        long long lo=1, hi=(sum/n),ans=-1;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if(check(mid,n,batteries)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
};

/*

    3,3,3
    2,2,3
    1,2,2
    1,1,1
    0,0,1

    n=k   => k
    n=k-1 =>  


    max => 22
    min - min(all numbers) => 1

    11111000

   10 7 4 1 (3)
    7 4 4 1 (1)
    6 4 3 1 (1)
    5 3 3 1 (1)
    4 3 2 1 (1)
    3 2 2 1 (1)
    2 2 1 1 (1)
    1 1 1 1 (1)
    1 1 0 0 (1)
    0 0 0 0
        11

    k min heap
    n-k max heap

*/