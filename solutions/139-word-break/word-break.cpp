class Solution__ {
public:
    int n,w;
    unordered_map<string,int> mp;
    vector<vector<int>> dp;
    int rec(string &s, int l, int r){
        if(mp.find(s.substr(l,r-l+1))!=mp.end()){
            return dp[l][r]=1;
        }
        if(dp[l][r]!=-1) return dp[l][r];
        bool ans=0;
        for(int mid=l;mid<r;mid++){
            if(rec(s,l,mid) && rec(s,mid+1,r)){
                ans=1;
                break;
            }
        }
        return dp[l][r]=ans;
    }

    bool wordBreak(string &s, vector<string>& wordDict) {
        n=s.length();
        w=wordDict.size();
        for(auto x: wordDict){
            mp[x]++;
        }
        dp.resize(n+1,vector<int>(n+1,-1));
        return rec(s,0,n-1);
    }
};

class Solution {
public:
    int n;
    unordered_map<string,int> mp;
    vector<int> dp;

    int rec(string &s, int i){
        if(i==n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        string cur="";
        int ans=0;

        for(int end=i;end<n;end++){
            cur+=s[end];
            if(mp.find(cur)!=mp.end() && rec(s,end+1)){
                ans=1;
                break;
            }
        }
        return dp[i]=ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        for(auto &x: wordDict){
            mp[x]++;
        }
        dp.assign(n+1,-1);
        return rec(s,0);
    }
};


/*

class Solution {
public:
    int n;
    unordered_map<string,int> mp;
    vector<int> dp;

    int rec(string &s, int i){
        if(i==n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        string cur="";
        int ans=0;

        for(int end=i;end<n;end++){
            cur+=s[end];
            if(mp.find(cur)!=mp.end() && rec(s,end+1)){
                ans=1;
                break;
            }
        }
        return dp[i]=ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        for(auto &x: wordDict){
            mp[x]++;
        }
        dp.assign(n+1,-1);
        return rec(s,0);
    }
};

*/