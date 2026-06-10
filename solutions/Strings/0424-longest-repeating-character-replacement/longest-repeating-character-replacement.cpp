class Solution {
public:

    vector<int> ans_vector;

    // O(n)
    int twoPointer(string s, int k, char c){
        int head=-1,tail=0,n=s.length(),swaps=0,ans=1;
        while(tail<n){
            while((head+1<n) && (s[head+1]==c || swaps<k)){
                head++;
                if(s[head]!=c){
                    swaps++;
                }
            }
            ans=max(ans, head-tail+1);
            if(head<tail){
                tail++;
                head=tail-1;
            }else{
                if(s[tail]!=c){
                    swaps--;
                }
                tail++;
            }
        }
        return ans;
    }

    int characterReplacement(string s, int k) {
        ans_vector.resize(26,0);
        int ans=1;
        // O(26*n)
        for(int i=0;i<26;i++){
            ans_vector[i]=twoPointer(s,k,'A'+i);
        }
        for(int i=0;i<26;i++){
            ans=max(ans,ans_vector[i]);
        }
        return ans;
    }
};