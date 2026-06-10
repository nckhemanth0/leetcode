class Solution {
public:
    // S,R
    int countCollisions(string directions) {
        int n=directions.size();
        int i=0,ans=0;
        stack<char> st;
        while(i<n){
            if(!st.empty()){
                char top=st.top();
                if(top=='R'){
                    if(directions[i]=='L'){
                        while(!st.empty() && st.top()=='R'){
                            ans++;
                            st.pop();
                        }
                        ans++;
                        st.push('S');
                    }else if(directions[i]=='S'){
                        while(!st.empty() && st.top()=='R'){
                            ans++;
                            st.pop();
                        }
                        st.push('S');
                    }else{
                        st.push('R');
                    }
                }else if(top=='S'){
                    if(directions[i]=='L'){
                        ans+=1;
                    }else if(directions[i]=='R'){
                        st.pop();
                        st.push('R');
                    }
                }
            }else if(directions[i]!='L'){
                st.push(directions[i]);
            }
            i++;
        }
        return ans;
    }
};