class Solution {
public:

    int compress(vector<char>& chars) {
        int n = (int)chars.size();
        int w = 0;

        for (int i = 0; i < n; ) {
            char x = chars[i];
            int j = i;
            while (j < n && chars[j] == x) j++;

            int cnt = j - i;

            chars[w++] = x;
            if (cnt > 1) {
                string s = to_string(cnt);
                for (char c : s) chars[w++] = c;
            }

            i = j; // jump to next group
        }
        return w;
    }


    int compress_(vector<char>& chars) {
        int cnt=1;
        int n=chars.size();
        int ans=0;
        int k=0;
        for(int i=1;i<n;i++){
            if(chars[i]==chars[i-1]){
                cnt++;
            }else{
                if(cnt==1){
                    chars[k++]=chars[i-1];
                }else{
                    chars[k++]=chars[i-1];
                    string x=to_string(cnt);
                    for(auto c: x){
                        chars[k++]=c;
                    }
                }
                cnt=1;
            }
        }
        if(cnt==1){
            chars[k++]=chars[n-1];
        }else{
            chars[k++]=chars[n-1];
            string x=to_string(cnt);
            for(auto c: x){
                chars[k++]=c;
            }
        }
        return k;
    }
};