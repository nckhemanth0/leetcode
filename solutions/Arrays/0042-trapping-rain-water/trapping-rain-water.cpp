class Solution {
public:

    // two pointer solution
    int trapTwoPointer(vector<int>& arr){
        int n=arr.size(),ans=0;
        int l=0, r=n-1;
        int leftMax=0,rightMax=n-1;
        while(l<=r){
            if(arr[l]<arr[r]){
                if(arr[l]<arr[leftMax]){
                    ans+=(arr[leftMax]-arr[l]);
                }else{
                    leftMax=l;
                }
                l++;
            }else{
                if(arr[r]<arr[rightMax]){
                    ans+=(arr[rightMax]-arr[r]);
                }else{
                    rightMax=r;
                }
                r--;
            }
        }
        return ans;
    }

    // stack solution
    int trap(vector<int>& arr) {
        int ans=0,n=arr.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]>arr[st.top()]){
                // arr[i] is next greater element for any arr[topIndex]
                int topIndex=st.top();
                st.pop();
                if(!st.empty()){
                    // arr[pge] is previous greater element for any arr[topIndex]
                    int pge=st.top();
                    int height=min(arr[pge],arr[i])-arr[topIndex];
                    int width=i-pge-1;
                    ans+=(height*width);
                }
            }
            st.push(i);
        }
        return ans;
    }

    // prefix & suffix max solution
    int trapDP(vector<int>& arr) {
        int n=arr.size();
        vector<int> maxLeft(n);
        vector<int> maxRight(n);

        for(int i=0;i<n;i++){
            maxLeft[i]=(i>=1)?(max(maxLeft[i-1],arr[i])):(arr[i]);
        }
        for(int i=n-1;i>=0;i--){
            maxRight[i]=(i<=n-2)?(max(maxRight[i+1],arr[i])):(arr[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(maxLeft[i],maxRight[i])-arr[i]);
        }
        return ans;
    }
};