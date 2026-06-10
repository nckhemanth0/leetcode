class Solution {
public:
    string getSmallestString(string s) {
        for(int i=0;i<s.length()-1;i++){
            if(s[i]>s[i+1] && (s[i]&1)==(s[i+1]&1)){
                swap(s[i],s[i+1]);
                return s;
            }
        }
        return s;
    }
};