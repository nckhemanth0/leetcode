class Solution {
    private class Pair{
        int freq;
        char c;

        Pair(int freq, char c){
            this.freq=freq;
            this.c=c;
        }
    }
    public String frequencySort(String s) {
        Map<Character,Integer> mp=new HashMap<>();
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            mp.put(c,mp.getOrDefault(c,0)+1);
        }
        Queue<Pair> pq=new PriorityQueue<>((a,b)->(b.freq-a.freq));
        for(var entry: mp.entrySet()){
            pq.offer(new Pair(entry.getValue(),entry.getKey()));
        }
        StringBuilder sb=new StringBuilder();
        while(!pq.isEmpty()){
            int cnt=pq.peek().freq;
            char ch=pq.peek().c;
            pq.poll();
            for(int i=0;i<cnt;i++){
                sb.append(ch);
            }
        }
        return sb.toString();
    }
}