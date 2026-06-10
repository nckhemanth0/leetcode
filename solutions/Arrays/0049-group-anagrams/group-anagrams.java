class Solution1 {
    public List<List<String>> groupAnagrams(String[] strs) {
        int n=strs.length;
        Map<String,List<String>> mp=new HashMap<>();
        for(var str: strs){
            char[] arr=str.toCharArray();
            Arrays.sort(arr);
            String sorted=new String(arr);
            mp.computeIfAbsent(sorted,k -> new ArrayList<>()).add(str);
        }
        return new ArrayList<>(mp.values());
    }
}

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int n=strs.length;
        Map<String,List<String>> mp=new HashMap<>();
        for(var str: strs){
            StringBuilder sb=new StringBuilder();
            int[] arr=new int[26];
            for(var x: str.toCharArray()){
                arr[x-'a']++;
            }
            for(int i=0;i<26;i++){
                sb.append(arr[i]).append('#');
            }
            mp.computeIfAbsent(sb.toString(),k -> new ArrayList<>()).add(str);
        }
        return new ArrayList<>(mp.values());
    }
}

