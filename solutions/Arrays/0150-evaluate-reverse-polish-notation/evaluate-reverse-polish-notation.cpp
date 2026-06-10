class Solution {
public:

    vector<string> operators={"+","-","*","/"};

    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<string> st;
        for(int i=0;i<n;i++){
            auto it=find(operators.begin(),operators.end(),tokens[i]);
            if(it!=operators.end()){
                int y=stoi(st.top());
                st.pop();
                int x=stoi(st.top());
                st.pop();
                if(tokens[i]=="+"){
                    st.push(to_string(x+y));
                }else if(tokens[i]=="-"){
                    st.push(to_string(x-y));
                }else if(tokens[i]=="*"){
                    st.push(to_string(x*y));
                }else if(tokens[i]=="/"){
                    st.push(to_string(x/y));
                }
            }else{
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};