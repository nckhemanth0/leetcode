class Solution {
public:
    string ops="+-*/";

    int calculate(string s) {
        stack<int> st;
        int n=s.size();
        long num=0;
        char op='+';
        for(int i=0;i<n;i++){
            char c=s[i];
            if(isdigit(c)){
                num=num*10+(c-'0');
            }
            if((!isdigit(c) && !isspace(c)) || i==n-1){
                if(op=='+'){
                    st.push(num);
                }else if(op=='-'){
                    st.push(-num);
                }else if(op=='*'){
                    int x=st.top();
                    st.pop();
                    st.push(x*num);
                }else{
                    int x=st.top();
                    st.pop();
                    st.push(x/num);
                }
                op=c;
                num=0;
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};