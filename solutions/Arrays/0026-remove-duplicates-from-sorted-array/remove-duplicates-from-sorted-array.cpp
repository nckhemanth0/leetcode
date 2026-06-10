class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=0;
        while(j<n){
            int val=arr[j];
            arr[i++]=val;
            while(j<n && arr[j]==val){
                j++;
            }
        }
        return i;
    }
};