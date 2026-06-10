class Solution {
    public int[] dailyTemperatures(int[] arr) {
        Deque<Integer> st=new ArrayDeque<>();
        int n=arr.length;
        int[] ans=new int[n];
        int j=n-1;
        for(int i=n-1;i>=0;i--){
            while(!st.isEmpty() && arr[i]>=arr[st.peek()]){
                st.pop();
            }
            if(st.isEmpty()){
                ans[j--]=0;
            }else{
                ans[j--]=st.peek()-i;
            }
            st.push(i);
        }
        return ans;
    }
}