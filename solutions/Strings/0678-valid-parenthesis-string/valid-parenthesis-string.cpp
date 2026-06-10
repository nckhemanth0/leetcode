class Solution {
public:
    unordered_map<int,unordered_map<int,int>> dp;
    bool rec(int level, int open, string &s,stack<char> st){
        if(level==s.length()){

            // check
            stack<char> st2;
            while(!st.empty()){
                if(st.top()==')'){
                    st2.push(')');
                    st.pop();
                }else if(st.top()=='('){
                    if(st2.empty()){
                        return false;
                    }else{
                        st2.pop();
                        st.pop();
                    }
                }
            }
            if(!st2.empty()){
                return false;
            }
            return true;
        }
        // cout<<"level: "<<level<<", open: "<<open<<endl;
        // stack st3=st;
        // vector<char> v;
        // while(!st3.empty()){
        //     v.push_back(st3.top());
        //     st3.pop();
        // }
        // reverse(v.begin(),v.end());
        // for(auto x: v){
        //     cout<<x;
        // }
        // cout<<endl;
        if(dp.find(level)!=dp.end() && dp[level].find(open)!=dp[level].end()){
            return dp[level][open];
        }
        
        bool ans=false;
        if(s[level]=='*'){
            st.push('(');
            ans|=rec(level+1,open+1,s,st);
            st.pop();
            st.push(')');
            ans|=rec(level+1,open-1,s,st);
            st.pop();
            ans|=rec(level+1,open,s,st);
        }else{
            st.push(s[level]);
            ans|=rec(level+1,open+(s[level]=='('?1:0),s,st);
            st.pop();
        }
        return dp[level][open]=ans;
    }

    bool checkValidString___complex_first_instinct(string s) {
        int n=s.length();
        int open=0;
        stack<char> st;
        return rec(0,open,s,st);
    }

    // ============= ================  ================== ============

    unordered_map<int, unordered_map<int, int>> dp2;

    bool rec(int level, int open, string &s) {
        if (open < 0) return false;
        if (level == s.size()) return open == 0;

        if (dp2[level].count(open)) return dp2[level][open];

        bool ans = false;
        if (s[level] == '(') ans = rec(level + 1, open + 1, s);
        else if (s[level] == ')') ans = rec(level + 1, open - 1, s);
        else ans = rec(level + 1, open, s) || rec(level + 1, open + 1, s) || rec(level + 1, open - 1, s);

        return dp2[level][open] = ans;
    }

    bool checkValidString(string s) {
        return rec(0, 0, s);
    }
};