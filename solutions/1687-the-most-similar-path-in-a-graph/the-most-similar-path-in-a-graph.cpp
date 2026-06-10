class Solution {
public:
    vector<vector<int>> adj;
    vector<int> curPath;
    unordered_map<string,int> mp;
    unordered_map<int,unordered_map<int,int>> path;
    int rec(int u, int level,vector<vector<int>>& roads,vector<string>& names,vector<string>& targetPath, vector<vector<int>> &dp){

        if(level==(targetPath.size()-1)){
            return names[u]!=targetPath[level];
        }
        if(dp[u][level]!=-1){
            return dp[u][level];
        }
        int ans=INT_MAX;
        int cur_cost=(names[u]!=targetPath[level]);
        for(auto v: adj[u]){
            curPath.push_back(v);
            int val=cur_cost+rec(v,level+1,roads,names,targetPath,dp);
            if(val<ans){
                ans=val;
                path[u][level]=v;
            }
            curPath.pop_back();
        }
        return dp[u][level]=ans;
    }

    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        adj.resize(n+1);
        for(auto x: roads){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int idx=0;
        for(auto name: names){
            mp[name]=idx++;
        }
        vector<vector<int>> dp(n+1,vector<int>(targetPath.size()+1,-1));
        int ans=INT_MAX;
        int startNode=0;
        for(int i=0;i<n;i++){
            int val=rec(i,0,roads,names,targetPath,dp);
            if(ans>val){
                ans=val;
                startNode=i;
            }
        }
        vector<int> finalAns={startNode};
        int i=0;
        while(i<targetPath.size()-1){
            finalAns.push_back(path[finalAns.back()][i++]);
        }
        return {finalAns};
        
    }
};

/*

same len path
min edit dist

*/