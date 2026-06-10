
class TrieNode{
public:
    TrieNode* children[27];
    int frequency;
    string sentence;

    TrieNode(){
        for(int i=0;i<27;i++){
            children[i]=nullptr;
        }
        frequency=0;
        sentence="";
    }

    void insert(string &sentence, int times){
        TrieNode* currNode=this;
        for(char x: sentence){
            int index=(x==' ')?26:(x-'a');
            if(currNode->children[index]==nullptr){
                currNode->children[index]=new TrieNode();
            }
            currNode=currNode->children[index];
        }
        currNode->frequency+=times;
        currNode->sentence=sentence;
    }

    TrieNode* search(string &prefix){
        TrieNode* currNode=this;
        for(auto x: prefix){
            int index=(x==' ')?26:(x-'a');
            if(currNode->children[index]==nullptr){
                return nullptr;
            }
            currNode=currNode->children[index];
        }
        return currNode;
    }
};

class AutocompleteSystem {
public:

    using pis=pair<int,string>;

    TrieNode* root;
    string currInput;

    struct cmp {
        bool operator()(pair<int,string> &a, pair<int,string> &b) {
            if(a.first == b.first) {
                return a.second < b.second; 
            }
            return a.first > b.first;
        }
    };

    priority_queue<pis,vector<pis>,cmp> pq;

    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root=new TrieNode();
        currInput="";
        for(int i=0;i<sentences.size();i++){
            root->insert(sentences[i],times[i]);
        }
    }

    void dfs(TrieNode* node){
        if(node==nullptr){
            return;
        }
        if(node->frequency>0){
            pq.push({node->frequency,node->sentence});
            if(pq.size()>3){
                pq.pop();
            }
        }
        for(int i=0;i<27;i++){
            dfs(node->children[i]);
        }
    }
    
    vector<string> input(char c) {
        vector<string> suggestions;
        if(c=='#'){
            root->insert(currInput,1);
            currInput="";
            return suggestions;
        }
        currInput+=c;
        TrieNode* prefixNode=root->search(currInput);
        if(prefixNode==nullptr){
            return suggestions;
        }
        pq = priority_queue<pis,vector<pis>,cmp>();
        dfs(prefixNode);
        while(!pq.empty()){
            suggestions.insert(suggestions.begin(),pq.top().second);
            pq.pop();
        }
        return suggestions;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */