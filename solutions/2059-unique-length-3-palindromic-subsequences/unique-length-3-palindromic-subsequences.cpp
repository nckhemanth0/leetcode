class Solution {
public:
    int countPalindromicSubsequence__1(string s) {
        int n=s.size();
        vector<pair<int,int>> firstLast(26,{-1,-1});
        vector<vector<int>> prefix(n, vector<int>(26,0));
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(firstLast[idx].first==-1){
                firstLast[idx].first=i;
            }else{
                firstLast[idx].second=i;
            }
            if(i-1>=0){
                prefix[i]=prefix[i-1];
            }
            prefix[i][idx]++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            int first=firstLast[i].first,last=firstLast[i].second;
            if(first!=-1 && last!=-1 && last-first>=2){
                int getDistinct=0;
                for(int k=0;k<26;k++){
                    getDistinct+=(prefix[last-1][k]-prefix[first][k])>=1;
                }
                ans+=getDistinct;
            }
        }
        return ans;
    }

    int countPalindromicSubsequence(string s) {
        vector<int> first = vector(26, -1);
        vector<int> last = vector(26, -1);
        
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (first[curr] == - 1) {
                first[curr] = i;
            }
            
            last[curr] = i;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) {
                continue;
            }
            unordered_set<char> between;
            for (int j = first[i] + 1; j < last[i]; j++) {
                between.insert(s[j]);
            }
            
            ans += between.size();
        }
        return ans;
    }
};