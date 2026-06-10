class Solution {
public:

    vector<string> ans;

    void rec(int level, int cnt, string str,int n){
        cout<<str<<endl;
        if(level>2*n || cnt<0 || cnt>n){
            return;
        }
        if(level==2*n){
            if(cnt==0){
                ans.push_back(str);
            }else{
                return;
            }
        }

        str+='(';
        rec(level+1,cnt+1,str,n);
        str.pop_back();
        str+=')';
        rec(level+1,cnt-1,str,n);
        str.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        int cnt=0;
        string str="";
        rec(0,cnt,str,n);
        return ans;
    }
};