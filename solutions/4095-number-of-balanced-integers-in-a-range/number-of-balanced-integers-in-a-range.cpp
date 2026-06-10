class Solution {
public:

        // dp[level][tlo][thi][sum]=rec(level,ntlo,thi,sum)+(level%2==0)?(nums[i]-'0'):('0'-nums[i])

    int n;
    string L,R;
    vector<vector<vector<unordered_map<int,long long>>>> dp;
    long long rec(int level, int tlo, int thi, int sum){
        if(level==n){
            if(sum==0){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[level][tlo][thi].count(sum)){
            return dp[level][tlo][thi][sum];
        }
        int lo=0;
        if(tlo==1){
            lo=L[level]-'0';
        }
        int hi=9;
        if(thi==1){
            hi=R[level]-'0';
        }
        long long ans=0;
        for(int i=lo;i<=hi;i++){
            int ntlo=tlo;
            if(i!=L[level]-'0'){
                ntlo=0;
            }
            int nthi=thi;
            if(i!=R[level]-'0'){
                nthi=0;
            }
            ans+=rec(level+1,ntlo,nthi,i-sum);
        }
        return dp[level][tlo][thi][sum]=ans;
    }

    
    long long countBalanced(long long low, long long high) {
        L=to_string(low);
        R=to_string(high);
        if(R.size()<2){
            return 0;
        }
        if(L.size()==1){
            L="10";
        }
        string append="";
        if(L.size()!=R.size()){
            for(int i=0;i<R.size()-L.size();i++){
                append.push_back('0');
            }
        }
        L=append+L;
        n=R.size();
        dp.assign(
            n, 
            vector<vector<unordered_map<int,long long>>>(2,
                vector<unordered_map<int,long long>>(2)
            )
        );
        return rec(0,1,1,0);
    }
};