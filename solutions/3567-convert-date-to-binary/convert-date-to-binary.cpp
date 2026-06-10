#include<sstream>
class Solution {
public:
    string binary(string s){
        int num=stoi(s);
        string out="";
        while(num){
            out=out+to_string(num%2);
            num/=2;
        }
        reverse(out.begin(),out.end());
        return out;
    }
    string convertDateToBinary(string date) {
        istringstream iss(date);
        string token;
        string ans="";
        while(getline(iss,token,'-')){
            ans+=binary(token);
            ans+='-';
        }
        ans.pop_back();
        return ans;
    }
};