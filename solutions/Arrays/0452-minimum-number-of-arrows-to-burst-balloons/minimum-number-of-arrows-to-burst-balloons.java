class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points,(x,y)->{
            if(x[0]!=y[0]){
                return Integer.compare(x[0],y[0]);
            }
            return Integer.compare(x[1],y[1]);
        });
        int n=points.length;
        int ans=0;
        int[] prev=points[0];
        for(int i=1;i<n;i++){
            if(points[i][0]<=prev[1]){
                prev[0]=Math.max(prev[0],points[i][0]);
                prev[1]=Math.min(prev[1],points[i][1]);
            }else{
                ans++;
                prev=points[i];
            }
        }
        return ans+1;
    }
}

// [1,6] [2,8] [7,12] [10,16]
// [1,2] [3,4] [5,6] [7,8]