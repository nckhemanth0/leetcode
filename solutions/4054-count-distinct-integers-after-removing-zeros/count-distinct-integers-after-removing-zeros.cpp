class Solution {
public:

    using ll = long long;

    string l,r;
    ll size;

    ll dp[16][2][2][2];

    ll rec(ll level, ll started, ll tlo, ll thi){
        if(level==size){
            // cout<<v<<endl;
            return 1;
        }
        if(dp[level][started][tlo][thi]!=-1){
            return dp[level][started][tlo][thi];
        }
        ll lo=0,hi=9;
        if(tlo){
            lo=l[level]-'0';
        }
        if(thi){
            hi=r[level]-'0';
        }
        ll ans=0;
        for(ll i=lo;i<=hi;i++){
            if(started && i==0){
                continue;
            }
            ll nstarted=started;
            if(!started && i!=0){
                nstarted=1;
            }
            ll ntlo=tlo;
            if(i!=l[level]-'0'){
                ntlo=0;
            }
            ll nthi=thi;
            if(i!=r[level]-'0'){
                nthi=0;
            }
            // v.push_back(i+'0');
            ans+=rec(level+1,nstarted,ntlo,nthi);
            // v.pop_back();
        }
        return dp[level][started][tlo][thi]=ans;
    }

    ll countDistinct(ll n) {
        memset(dp,-1,sizeof(dp));
        r=to_string(n);
        size=r.size();
        l="1";
        ll cnt=r.size()-l.size();
        string temp="";
        while(cnt--){
            temp+='0';
        }
        l=temp+l;
        // cout<<l<<" "<<r<<endl;
        // string v="";
        return rec(0,0,1,1);
    }
};