class Solution {
public:

    bool isValid(string s) {
        stack<int> st;
        for(auto x:s){
            if(!st.empty()){
                char v=st.top();
                if((x==')' && v=='(') || (x=='}' && v=='{') || (x==']' && v=='[')){
                    st.pop();
                }else{
                    st.push(x);
                }
            }else{
                st.push(x);
            }
        }
        return st.empty();
    }

    bool isValid__basic_v1(string s) {
        unordered_map<char,char> mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';
        stack<int> st;
        for(auto x:s){
            if(!st.empty() && mp[x]==st.top()){
                st.pop();
            }else{
                st.push(x);
            }
        }
        return st.empty();
    }
};