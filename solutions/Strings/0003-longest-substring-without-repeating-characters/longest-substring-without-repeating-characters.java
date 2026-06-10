class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n=s.length();
        int l=0;
        int ans=Integer.MIN_VALUE;
        Map<Character,Integer> mp=new HashMap<>();
        for(int r=0;r<n;r++){
            mp.put(s.charAt(r),mp.getOrDefault(s.charAt(r),0)+1);
            while(mp.get(s.charAt(r))>1){
                mp.put(s.charAt(l),mp.get(s.charAt(l))-1);
                l++;
            }
            ans=Integer.max(ans,r-l+1);
        }
        return ans==Integer.MIN_VALUE?0:ans;
    }
}