class Solution {
    public String reverseWords(String s) {
        StringBuffer sb=new StringBuffer(s);
        int n=s.length(),i=0;
        while(i<n){
            while(i<n && sb.charAt(i)==' '){
                i++;
            }
            int end=i;
            while(end<n && sb.charAt(end)!=' '){
                end++;
            }
            int j=end-1;
            while(i<j){
                char temp=sb.charAt(i);
                sb.setCharAt(i++, sb.charAt(j));
                sb.setCharAt(j--, temp);
            }
            i=end;
        }
        return sb.toString();
    }
}