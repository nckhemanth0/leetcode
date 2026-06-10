class Solution {
public:
    unordered_map<char,vector<char>> adj;
    unordered_map<char,int> indegree;
    bool add(string &word1, string &word2){
        int n1=word1.size();
        int n2=word2.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(word1[i]==word2[j]){
                i++;
                j++;
                continue;
            }else{
                adj[word1[i]].push_back(word2[j]);
                indegree[word2[j]]++;
                return true;
            }
        }
        if(i<n1){
            return false;
        }
        return true;
    }
    string alienOrder(vector<string>& words) {
        int n=words.size();
        for(auto x: words){
            for(auto y: x){
                indegree[y]=0;
            }
        }
        for(int i=0;i<n-1;i++){
            if(!add(words[i],words[i+1])){
                return "";
            }
        }
        queue<char> q;
        for(auto x: indegree){
            if(x.second==0){
                q.push(x.first);
            }
        }
        string ans="";
        while(!q.empty()){
            char u=q.front();
            q.pop();
            ans+=u;
            for(auto v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        for(auto x: indegree){
            if(x.second!=0){
                return "";
            }
        }
        return ans;
    }
};

// ba, za

// er, etw