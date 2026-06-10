class Solution {
public:

    // O(1) space
    // Remember: (head<tail) case while incrementing or decrementing in while loop
    bool isPalindrome(string s) {
        for(int head=0,tail=s.size()-1;head<tail;head++,tail--){
            while((head<tail) && !isalnum(s[head])){
                head++;
            }
            while((head<tail) && !isalnum(s[tail])){
                tail--;
            }
            if(tolower(s[head])!=tolower(s[tail])){
                return false;
            }
        }
        return true;
    }

    bool isPalindrome__nspace(string s) {
        string ns="";
        for(auto x: s){
            if(isalnum(x)){
                ns+=tolower(x);
            }
        }
        int head=0, tail=ns.size()-1;
        while(head<tail){
            if(ns[head++]!=ns[tail--]){
                return false;
            }
        }
        return true;
    }
};