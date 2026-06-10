class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        for(auto w: wordList){
            mp[w]++;
        }
        unordered_map<string,int> dis;
        queue<string> q;
        q.push(beginWord);
        dis[beginWord]=1;
        while(!q.empty()){
            string u=q.front();
            q.pop();
            if(u==endWord){
                return dis[u];
            }
            for(int i=0;i<u.size();i++){ // index of u node
                string temp=u;
                for(int j=0;j<26;j++){ // a-z for that index
                    temp[i]='a'+j;
                    if(mp[temp] && dis.find(temp)==dis.end()){
                        dis[temp]=dis[u]+1; // so multiple such nodes will node be in queu at a time. We know the first time we push is the best in unwieghted BFS
                        q.push(temp);
                    }
                }
            }
        }
        return 0;
    }


    // =============== =============== =============== =============== ===============

    /*
        Method 2: (My reasoning from editorial: Node Referencing)
            use wordlist for preprocessing and creation of graph nodes instead of our above method of using map
            like in 1st ex:
                *ot, h*t,ho*, these all points -> hit (edges)
                the same for all the words in the wordList
            now begin word - hit, can be:
                *it, h*t, hi*
                so we have these above three as ***reference node*** to the begin node
                now from these 3 reference node we can we can word is reachable that we made in preprocessing
                so with distance 1 hit can go to hot (since h*t -> hit edge is present)
    



                            int ladderLength(string beginWord, string endWord,
                                            vector<string>& wordList) {
                                int L = beginWord.size();
                                unordered_map<string, vector<string>> allComboDict;
                                for (string word : wordList) {
                                    for (int i = 0; i < L; i++) {
                                        string newWord =
                                            word.substr(0, i) + '*' + word.substr(i + 1, L);
                                        allComboDict[newWord].push_back(word);
                                    }
                                }
                                queue<pair<string, int>> Q;
                                Q.push(make_pair(beginWord, 1));
                                unordered_map<string, bool> visited;
                                visited[beginWord] = true;
                                while (!Q.empty()) {
                                    pair<string, int> node = Q.front();
                                    Q.pop();
                                    string word = node.first;
                                    int level = node.second;
                                    for (int i = 0; i < L; i++) {
                                        string newWord =
                                            word.substr(0, i) + '*' + word.substr(i + 1, L);
                                        for (string adjacentWord : allComboDict[newWord]) {
                                            if (adjacentWord == endWord) {
                                                return level + 1;
                                            }
                                            if (!visited[adjacentWord]) {
                                                visited[adjacentWord] = true;
                                                Q.push(make_pair(adjacentWord, level + 1));
                                            }
                                        }
                                    }
                                }
                                return 0;
                            }
    */
};