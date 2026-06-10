class Solution {
    public boolean isValid(String s) {
        Deque<Character> st=new ArrayDeque<>();
        String open="({[";
        String closed=")}]";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(open.indexOf(s.charAt(i))!=-1){
                st.push(s.charAt(i));
            }else{
                int index=closed.indexOf(s.charAt(i));
                if(!st.isEmpty() && open.indexOf(st.peek())==index){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.isEmpty();
    }
}