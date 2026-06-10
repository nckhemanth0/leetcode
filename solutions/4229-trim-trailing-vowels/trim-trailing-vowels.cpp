class Solution {
public:
    string trimTrailingVowels(string s) {
        int n=s.size();
        string x="aeiou";
        for(int i=n-1;i>=0;i--){
            if(x.find(s[i])!=string::npos){
                s.pop_back();
            }else{
                break;
            }
        }
        return s;
    }
};