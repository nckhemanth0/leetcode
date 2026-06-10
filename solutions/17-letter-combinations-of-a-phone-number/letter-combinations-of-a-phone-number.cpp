class Solution {
public:
    vector<string> v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> final_ans;
    
    /*.  => working code only
        void rec(int level, string &digits, string ans){
            if(level==digits.size()){
                final_ans.push_back(ans);
                return;
            }
            string s=v[digits[level]-'0'];
            for(int i=0;i<s.size();i++){
                ans+=s[i];
                rec(level+1,digits,ans);
                ans.pop_back();
            }
        }

        vector<string> letterCombinations(string digits) {
            rec(0,digits,"");
            return final_ans;
        }
    */

    void rec(int level, string &digits,string ans){
        if(level==digits.size()){
            final_ans.push_back(ans);
            return;
        }
        string s=v[digits[level]-'0'];
        for(int i=0;i<s.size();i++){
            rec(level+1,digits,ans+s[i]);
        }
    }

    vector<string> letterCombinations(string digits) {
            string ans="";
        rec(0,digits,ans);
        return final_ans;
    }
};