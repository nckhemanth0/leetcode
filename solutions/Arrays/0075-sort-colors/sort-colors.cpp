class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        int lo=0,mid=0,hi=n-1;
        while(mid<=hi){ // = because after swap, 'mid' might still not be in place
            if(arr[mid]==0){
                swap(arr[lo],arr[mid]);
                lo++;
                mid++;
            } else if(arr[mid]==1){
                mid++;
            } else if(arr[mid]==2){
                swap(arr[mid],arr[hi]); // possibility of 2 getting swapped with 0 instead of 1 (that mid again need to be taken care)
                hi--;
            }
        }
    }
};

// 0 2 0 0 1
// 0 0 0 1 2 1 0