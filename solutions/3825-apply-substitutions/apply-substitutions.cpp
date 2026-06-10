class Solution {
public:
    unordered_map<string,string> mp;
    unordered_map<string,string> dp;

    string dfs(string key){
        if(dp.count(key)){
            return dp[key];
        }
        string val=mp[key];
        string ans=parse(val);
        return dp[key]=ans;
    }
    string parse(string text){
        int n=text.size();
        string ans="";
        for(int i=0;i<n;){
            if(text[i]=='%'){
                string key="";
                int j=i+1;
                while(text[j]!='%'){
                    key+=text[j];
                    j++;
                }
                ans+=dfs(key);
                i=j+1;
            }else{
                ans+=text[i];
                i++;
            }
        }
        return ans;
    }
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        for(auto x: replacements){
            mp[x[0]]=x[1];
        }
        return parse(text);
    }
};