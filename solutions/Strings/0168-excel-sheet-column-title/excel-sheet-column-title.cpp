class Solution {
public:
    char f(int num){
        return num+'A';
    }
    string ans="";
    string convertToTitle(int columnNumber) {
        while(columnNumber){
            columnNumber--;
            int c=columnNumber%26;
            ans+=f(c);
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};