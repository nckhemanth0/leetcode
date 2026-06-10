class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int n=s.size();
        int num=0;
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                st.push(to_string(num));
                num=0;
            }else if(std::isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }else if(s[i]==']'){
                string x="";
                while(!st.empty() && std::isalpha(st.top()[0])){
                    x+=st.top();
                    st.pop();
                }
                int cnt=stoi(st.top());
                st.pop();
                string res="";
                for(int k=0;k<cnt;k++) {
                    res+=x;
                }
                st.push(res);
            }else{
                string character(1,s[i]);
                st.push(character);
            }
        }
        string ans="";
        while(!st.empty() && std::isalpha(st.top()[0])){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};