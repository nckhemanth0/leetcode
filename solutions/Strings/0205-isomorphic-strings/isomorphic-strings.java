class Solution {
    public boolean isIsomorphic(String s, String t) {
        int n1=s.length();
        int n2=t.length();
        if(n1!=n2){
            return false;
        }
        Map<Character,Character> mp=new HashMap<Character,Character>();
        Set<Character> set=new HashSet<>();
        int i=0;
        while(i<n1){
            Character x=s.charAt(i);
            Character y=t.charAt(i);
            if((mp.containsKey(x) && !mp.get(x).equals(y)) || (!mp.containsKey(x) && set.contains(y))){
                return false;
            }
            mp.put(x,y);
            set.add(y);
            // mp.put(t.charAt(i),s.charAt(i));
            i++;
        }
        return true;
    }
}