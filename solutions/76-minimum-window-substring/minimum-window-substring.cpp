class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int> mp_s,mp_t;
        int head=-1,tail=0,n_s=s.length(),n_t=t.size(),st;
        int sum=0; // tracks num of matches aahgdbc & abc => 2nd should be treated as unknown char
        int ans_length=n_s+1; // single char case wehere ans is n_s
        for(auto x: t){
            mp_t[x]++; // for comparision, to maintain sum DS
        }
        while(tail<n_s){
            while((head+1<n_s) && (sum<t.length())){
                head++;
                if(mp_s[s[head]]<mp_t[s[head]]){
                    sum++; // store the total char count of match
                }
                mp_s[s[head]]++; // char count in the window
            }
            if(sum==t.length() && ans_length>head-tail+1){
                ans_length=head-tail+1;
                st=tail;
            }
            mp_s[s[tail]]--;
            if(mp_s[s[tail]]<mp_t[s[tail]]){
                sum--;
            }
            tail++;
        }
        return ans_length==n_s+1 ? "" : s.substr(st,ans_length);
    }
};