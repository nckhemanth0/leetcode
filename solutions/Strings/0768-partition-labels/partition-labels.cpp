class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        unordered_map<char,int> last;
        for(int i=0;i<n;i++){
            last[s[i]]=i;
        }
        int i=0;
        vector<int> ans;
        while(i<n){
            int cnt=0;
            int end=last[s[i]];
            while(i<=end){
                cnt++;
                if(last[s[i]]>end){
                    end=last[s[i]];
                }
                i++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};