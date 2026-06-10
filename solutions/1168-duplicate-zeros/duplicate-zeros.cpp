class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        int sum=0,i=0;
        for(;i<n;i++){
            if(arr[i]==0){
                sum+=2;
            }else{
                sum+=1;
            }
            if(sum>=n){
                break;
            }
        }
        for(int j=n-1;j>=0;){
            if(sum>n){
                arr[j]=0;
                sum--;
                i--;
                j--;
                continue;
            }
            if(arr[i]==0){
                arr[j]=0;
                arr[j-1]=0;
                i--;
                j-=2;
            }else{
                arr[j]=arr[i];
                i--;
                j--;
            }
        }
    }
};