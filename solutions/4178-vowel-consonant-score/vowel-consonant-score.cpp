class Solution {
public:
    int vowelConsonantScore(string s) {
        int v=0;
        string vowel="aeiou";
        int n=s.size();
        int all=0;
        for(int i=0;i<n;i++){
            if(!isalpha(s[i])){
                continue;
            }
            if(vowel.find(s[i])!=string::npos){
                v++;
            }
            all++;
        }
        int c=all-v;
        if(c==0){
            return 0;
        }else{
            return (v/c);
        }
    }
};