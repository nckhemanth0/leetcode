class Solution {
public:
    using ll=long long;
    map<int,int> mp;
    unordered_map<int,int> prev;
    string L,R;
    int len=16;
    unordered_map<string,ll> dp;
    // string pre="";

    string key(int level, int tlo, int thi, int prev_level){
        string k=to_string(level)+"#"+to_string(tlo)+"#"+to_string(thi)+"#"+to_string(prev_level);
        // for(auto x: mp){
        //     k+=to_string(x.first)+":"+to_string(x.second);
        // }
        return k;
    }
    
    ll rec(int level, int tlo, int thi, int prev_level){
        if(level==len){
            return 1;
        }
        string k=key(level,tlo,thi,prev_level);
        if(dp.count(k)){
            return dp[k];
        }
        int lo=tlo ? (L[level]-'0') : 0;
        int hi=thi ? (R[level]-'0') : 9;
        ll ans=0;
        if(prev.count(level) && prev_level!=-1){
            lo=max(lo,prev_level);
        }
        for(int d=lo;d<=hi;d++){
            int ntlo=tlo && (d==(L[level]-'0'));
            int nthi=thi && (d==(R[level]-'0'));
            int last;
            int new_prev_level=prev_level;
            if(mp.count(level)){
                last=mp[level];
                new_prev_level=mp[level]=d;
            }
            // pre+=(d+'0');
            ans+=rec(level+1,ntlo,nthi,new_prev_level);
            if(mp.count(level)){
                mp[level]=last;
            }
            // pre.pop_back();
        }
        return dp[k]=ans;
    }
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        int tr=0,tc=0;
        mp[0]=-1;
        prev[0]=-1;
        int last=0;
        for(auto x: directions){
            if(x=='D'){
                tr+=1;
            }else{
                tc+=1;
            }
            mp[4*tr+tc]=-1;
            prev[4*tr+tc]=last;
            last=4*tr+tc;
        }
        L=to_string(l);
        R=to_string(r);
        L=string(len-L.size(),'0')+L;
        R=string(len-R.size(),'0')+R;
        return rec(0,1,1,-1);
    }
};

/*
directions - 3d's, 3r's
x in range [l,r]
x => len 16 if not pad left with 0's
place 16 digits in grid 4*4
start from (0,0), apply 6 chars (d => row+1, R => col+1)
seq of digits along path of len 7

x is good if seq is non dec order
num of such good x's
*/