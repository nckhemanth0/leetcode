class Solution {
    public int[][] merge(int[][] intervals) {
        int n=intervals.length;
        Arrays.sort(intervals,(int[] a, int[] b) -> {
            if(a[0]!=b[0]){
                return Integer.compare(a[0],b[0]);
            }
            return Integer.compare(a[1],b[1]);
        });
        List<int[]> list=new ArrayList<>();
        int[] back=intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>back[1]){
                list.add(back);
                back=intervals[i];
            }else{
                back[1]=Integer.max(back[1],intervals[i][1]);
            }
        }
        list.add(back);
        return list.toArray(new int[0][]);
    }
}