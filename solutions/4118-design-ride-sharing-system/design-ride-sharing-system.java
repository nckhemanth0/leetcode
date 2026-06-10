class Comp implements Comparator<int[]>{
    public int compare(int[] a, int[] b){
        int c=Integer.compare(a[0],b[0]);
        return c!=0?c:Integer.compare(a[1],b[1]);
    }
}

class RideSharingSystem {

    TreeSet<int[]> rider=new TreeSet<>(new Comp());
    TreeSet<int[]> driver=new TreeSet<>(new Comp());
    int rc=0,dc=0;
    Set<Integer> riderIds=new HashSet<>(); 
    
    public RideSharingSystem() {
        
    }
    
    public void addRider(int riderId) {
        rider.add(new int[]{rc++,riderId});
        riderIds.add(riderId);
    }
    
    public void addDriver(int driverId) {
        driver.add(new int[]{dc++,driverId});
    }
    
    public int[] matchDriverWithRider() {
        if(driver.isEmpty() || rider.isEmpty()){
            return new int[]{-1,-1};
        }
        int[] d=driver.first();
        int[] r=rider.first();
        int[] ans= new int[]{d[1],r[1]};
        riderIds.remove(r[1]);
        driver.pollFirst();
        rider.pollFirst();
        return ans;
    }
    
    public void cancelRider(int riderId) {
        if(riderIds.contains(riderId)){
            riderIds.remove(riderId);
            rider.stream().filter(r -> r[1]==riderId).findFirst().ifPresent(rider::remove);
        }
    }
}

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem obj = new RideSharingSystem();
 * obj.addRider(riderId);
 * obj.addDriver(driverId);
 * int[] param_3 = obj.matchDriverWithRider();
 * obj.cancelRider(riderId);
 */