class Solution {
public:
    string v="aeiou";
    int find(string x){
        int cnt=0;
         for(auto y: x){
             if(v.find(y)!=string::npos){
                 cnt++;
             }
         }
        return cnt;
    }
    string reverseWords(string s) {
        istringstream iss(s);
        string token;
        int cnt=0,req=0;
        string ans="";
        while(iss>>token){
            cout<<find(token)<<endl;
            if(cnt==0){
                req=find(token);
                ans+=token;
                ans+=" ";
                cnt++;
                continue;
            }
            if(find(token)==req){
                string temp=token;
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=" ";
            }else{
                ans+=token;
                ans+=" ";
            }
            cnt++;
        }
        ans.pop_back();
        return ans;
    }
};