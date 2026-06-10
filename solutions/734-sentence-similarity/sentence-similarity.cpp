class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size()!=sentence2.size()){
            return false;
        }
        unordered_set<string> mp;
        for(auto x: similarPairs){
            mp.insert(x[0]+"#"+x[1]);
            mp.insert(x[1]+"#"+x[0]);
        }
        for(int i=0;i<sentence1.size();i++){
            if(sentence1[i]!=sentence2[i] && !mp.count(sentence1[i]+"#"+sentence2[i])){
                return false;
            }
        }
        return true;
    }
};