/*
    class Cmp implements Comparator<int[]> {
        public int compare(int[] a, int[] b){
            if(a[0]!=b[0]){
                return Integer.compare(a[0],b[0]);
            }
            return Integer.compare(a[1],b[1]);
        }
    }
*/
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        /*
            Comparator<int[]> cmp=new Comparator<>(){
                public int compare(int[] a, int[] b){
                    if(a[0]!=b[0]){
                        return Integer.compare(a[0],b[0]);
                    }
                    return Integer.compare(a[1],b[1]);
                }
            };

            Comparator<int[]> cmp=Comparator.<int[]>comparingInt(a -> a[0]).thenComparingInt(a -> a[1])
        */
        Queue<int[]> q=new PriorityQueue<int[]>((int[] a, int[] b)->{
            if(a[0]!=b[0]){
                return Integer.compare(a[0],b[0]);
            }
            return Integer.compare(a[1],b[1]);
        });
        int n=nums.length;
        Map<Integer,Integer> mp=new HashMap<>();
        for(var x: nums){
            mp.put(x,mp.getOrDefault(x, 0)+1);
        }
        for(var x: mp.keySet()){
            q.offer(new int[]{mp.get(x),x});
            if(q.size()>k){
                q.poll();
            }
        }
        List<Integer> ans=new ArrayList<>();
        while(!q.isEmpty()){
            ans.add(q.poll()[1]);
        }
        return ans.stream().mapToInt(x->x.intValue()).toArray();
    }
}