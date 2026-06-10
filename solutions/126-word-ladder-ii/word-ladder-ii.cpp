class Solution {
public:
    unordered_map<string,vector<string>> par;
    vector<string> path;
    vector<vector<string>> ans;
    void dfs(string endWord){
        path.push_back(endWord);
        if(par[endWord].size()==0){
            vector<string> rev=path;
            reverse(rev.begin(),rev.end());
            ans.push_back(rev);
        }
        for(auto v: par[endWord]){
            dfs(v);
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        unordered_map<string,int> dist;
        unordered_set<string> set(wordList.begin(),wordList.end());
        while(!q.empty()){
            string u=q.front();
            q.pop();
            if(u==endWord){
                break;
            }
            string v=u;
            for(int i=0;i<v.size();i++){
                char cur=v[i];
                for(char x='a';x<='z';x++){
                    if(x==cur){
                        continue;
                    }
                    v[i]=x;
                    if(set.count(v)==0){
                        continue;
                    }
                    if(dist.count(v)==0){
                        dist[v]=dist[u]+1;
                        q.push(v);
                        par[v].push_back(u);
                    }else if(dist[v]==dist[u]+1){
                        par[v].push_back(u);
                    }
                }
                v[i]=cur;
            }
        }
        if(dist[endWord]==0){
            return {};
        }
        dfs(endWord);
        return ans;
    }
};


/*

class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parents;

    vector<string> neighbors(string word, unordered_set<string>& dict) {
        vector<string> res;

        for (int i = 0; i < word.size(); i++) {
            char old = word[i];

            for (char c = 'a'; c <= 'z'; c++) {
                if (c == old) continue;
                word[i] = c;

                if (dict.count(word))
                    res.push_back(word);
            }

            word[i] = old;
        }

        return res;
    }

    void dfs(string word, string& beginWord, vector<string>& path) {
        if (word == beginWord) {
            auto temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto& p : parents[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        queue<string> q;
        unordered_map<string, int> dist;

        q.push(beginWord);
        dist[beginWord] = 0;

        while (!q.empty()) {
            string curr = q.front(); q.pop();
            int d = dist[curr];

            for (auto& nei : neighbors(curr, dict)) {

                if (!dist.count(nei)) {
                    dist[nei] = d + 1;
                    parents[nei].push_back(curr);
                    q.push(nei);
                }
                else if (dist[nei] == d + 1) {
                    parents[nei].push_back(curr);
                }
            }
        }

        if (!dist.count(endWord)) return {};

        vector<string> path = {endWord};
        dfs(endWord, beginWord, path);

        return ans;
    }
};

*/