class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long sum_mod=0;
        vector<int> ans;
        for(int i=0;i<word.size();i++){
            sum_mod=(sum_mod*10+(word[i]-'0'))%m;
            if(sum_mod==0){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};