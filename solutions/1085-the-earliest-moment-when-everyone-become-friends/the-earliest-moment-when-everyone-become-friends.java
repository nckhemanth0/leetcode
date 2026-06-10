public class UF{
    private int[] parent;
    private int[] size;
    private int c;

    UF(int n){
        parent=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        size=new int[n];
        Arrays.fill(size,0);
        c=n;
    }
    public int find(int u){
        if(u!=parent[u]){
            return parent[u]=find(parent[u]);
        }
        return u;
    }
    public int merge(int u,int v){
        int xu=find(u),xv=find(v);
        if(xu!=xv){
            if(size[xu]>size[xv]){
                int temp1=xu;
                xu=xv;
                xv=temp1;
                int temp2=u;
                u=v;
                v=temp2;
            }
            size[xv]+=size[xu];
            parent[xu]=xv;
            c--;
            return 1;
        }else{
            return 0;
        }
    }
    public int getC(){
        return c;
    }
}

class Solution {
    public int earliestAcq(int[][] logs, int n) {
        Arrays.sort(logs,(x,y)->{
            return Integer.compare(x[0],y[0]);
        });
        UF uf=new UF(n);
        for(int i=0;i<logs.length;i++){
            int u=logs[i][1];
            int v=logs[i][2];
            uf.merge(u,v);
            if(uf.getC()==1){
                return logs[i][0];
            }
        }
        return -1;
    }
}

// 0,1,2,3,8,9

// 0,1,2,3