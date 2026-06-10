class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k=p.length();
        int n=s.length();
        vector<int> mp_s(26,0);
        vector<int> mp_p(26,0);
        for(auto y: p){
            mp_p[y-'a']++;
        }
        int cnt=0; // if both maps matched
        vector<int> ans;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            mp_s[idx]++;
            if(mp_s[idx]<=mp_p[idx]){
                cnt++;
            }

            if(i-k>=0){
                int last_window_idx=s[i-k]-'a';
                if(mp_s[last_window_idx]<=mp_p[last_window_idx]){
                    cnt--;
                }
                mp_s[last_window_idx]--;
            }

            if(i>=k-1 && cnt==k){
                ans.push_back(i-k+1);
            }
        }
        return ans;
    }

    // ======= ======= ======= ====== =========

    vector<int> findAnagrams__same_logic_but_simpler(string s, string p) {
        int k=p.length();
        int n=s.length();
        vector<int> mp_s(26,0);
        vector<int> mp_p(26,0);
        for(auto y: p){
            mp_p[y-'a']++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            mp_s[idx]++;

            if(i-k>=0){
                int last_window_idx=s[i-k]-'a';
                mp_s[last_window_idx]--;
            }

            if(i>=k-1 && mp_s==mp_p){
                ans.push_back(i-k+1);
            }
        }
        return ans;
    }
};