class Solution {
public:
    bool valid(string s){
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
            }else if(s[i]==')'){
                cnt--;
            }else{
                continue;
            }
            if(cnt<0){
                return false;
            }
        }
        return cnt==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.length();
        queue<string> q;
        unordered_map<string,int> vis;
        q.push(s);
        vis[s]=1;
        vector<string> ans;
        bool found=false;
        while(!q.empty() && !found){
            int sz=q.size();
            while(sz--){
                auto u=q.front();
                q.pop();
                if(valid(u)){
                    ans.push_back(u);
                    found=true;
                    continue;
                }
                for(int i=0;i<u.size();i++){
                    if(u[i]!='(' && u[i]!=')'){
                        continue;
                    }
                    string v=u.substr(0,i)+u.substr(i+1);
                    if(!vis[v]){
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
        }
        return ans;
    }
};