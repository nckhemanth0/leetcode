class Solution {
public:

    // Two Pointer solution
    bool hasSpecialSubstring(string arr, int k) {
        int n=arr.length();
        int head=-1,tail=0;
        int freq[26];
        int cnt=0;
        while(tail<(n-k+1)){
            while((head+1)<n && (head+1)<=tail+k-1){
                head++;
                freq[arr[head]-'a']++;
            }
            if(freq[arr[head]-'a']==k && (head+1>=n || (arr[head+1]!=arr[head])) && (tail-1<0 || (arr[tail-1]!=arr[tail]))){
                return true;
            }
            if(tail>head){
                tail++;
                head=tail-1;
            }else{
                freq[arr[tail]-'a']--;
                tail++;
            }
        }
        return false;
    }

    //Sliding window of fixed length solution
    bool hasSpecialSubstringSlidingWindow(string arr, int k) {
        int n=arr.length();
        int freq[26];
        int cnt=0;
        for(int i=0;i<n;i++){
            freq[arr[i]-'a']++;
            if(i>=k){
                freq[arr[i-k]-'a']--;
            }
            if(i>=k-1){
                if(freq[arr[i]-'a']==k && (i+1>=n || (arr[i+1]!=arr[i])) && (i-k<0 || (arr[i-k]!=arr[i-k+1]))){
                    return true;
                }
            }
        }
        return false;
    }
    
    // basic looping
    bool hasSpecialSubstring_initial(string arr, int k) {
        int i=1,n=arr.length();
        if(n==1){
            return true;
        }
        while(i<n){
            int cnt=1;
            int x=0;
            while(arr[i-1]==arr[i]){
                x++;
                cnt++;
                i++;
            }
            if(cnt==k){
                return true;
            }
            if(x==0){
                i++;
            }
        }
        return false;
    }
};