class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals,(int[] a, int[] b)->{
            if(a[0]!=b[0]){
                return a[0]-b[0];
            }
            return a[1]-b[1];
        });
        Queue<Integer> pq=new PriorityQueue<>(Comparator.reverseOrder());
        int n=intervals.length;
        for(int i=0;i<n;i++){
            var cur=intervals[i];
            int start=cur[0];
            int end=cur[1];
            while(!pq.isEmpty() && end<pq.peek()){
                pq.poll();
            }
            if(pq.isEmpty() || start>=pq.peek()){
                pq.offer(end);
            }
        }
        return n-pq.size();
    }
}

/*

easy sol: sort by end only

*/