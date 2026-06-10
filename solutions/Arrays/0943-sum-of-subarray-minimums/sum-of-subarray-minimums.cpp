class Solution {
public:
    const int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long ans=0;
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top();
            }else{
                pse[i]=-1;
            }
            st.push(i);
        }
        stack<int> st2;
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && arr[i]<=arr[st2.top()]){
                st2.pop();
            }
            if(!st2.empty()){
                nse[i]=st2.top();
            }else{
                nse[i]=n;
            }
            st2.push(i);
        }
        for(int i=0;i<arr.size();i++){
            long long x=(i-pse[i])%MOD;
            long long y=(nse[i]-i)%MOD;
            ans=(ans%MOD+(x*y)*(arr[i]))%MOD;
        }
        return (int)ans;
    }
};