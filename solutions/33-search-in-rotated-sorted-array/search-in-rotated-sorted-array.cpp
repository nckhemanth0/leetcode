class Solution {
public:
    int n;

    // for any mid, atmost one of the half is sorted and other contains mixed
    int search(vector<int>& nums, int target) {
        n=nums.size();
        int lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                return mid;
            }else{
                // left sorted?
                if(nums[mid]>=nums[lo]){
                    // is target in left half?
                    if(target>=nums[lo] && target<=nums[mid]){
                        hi=mid-1;
                    }else{
                        lo=mid+1;
                    }
                }else{
                    if(target>=nums[mid] && target<=nums[hi]){
                        lo=mid+1;
                    }else{
                        hi=mid-1;
                    }
                }
            }
        }
        return -1;
    }

    // considering pivot to pivot-1 as sorted circular array
    // normal to shifted index we need to add shift and %n
    // shifted to normal index we need to subtract shift and add n and %n
    int shiftedBinarySearch(vector<int>& nums, int pivot, int target) {
        int n = nums.size();
        int shift = n - pivot;
        int left = (pivot + shift) % n;
        int right = (pivot - 1 + shift) % n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[(mid - shift + n) % n] == target) {
                return (mid - shift + n) % n;
            } else if (nums[(mid - shift + n) % n] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    int binarySearch(vector<int>& nums,int target, int lo, int hi){
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return -1;
    }

    int getpivot(vector<int>& nums, int target){
        int lo=0,hi=n-1;
        int ans=n;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<nums[0]){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }

    int search_(vector<int>& nums, int target) {
        n=nums.size();
        int pivot=getpivot(nums,target)%n;
        int ans=-1;
        if(target>=nums[pivot] && target<=nums[n-1]){
            // auto it=lower_bound(nums.begin()+pivot,nums.end(),target);
            // if(it!=nums.end() && *it==target){
            //     ans=it-nums.begin();
            // }
            return binarySearch(nums, target, pivot, n - 1);
        }else{
            // auto it=lower_bound(nums.begin(),nums.begin()+pivot,target);
            // if(it!=nums.begin()+pivot && *it==target){
            //     ans=it-nums.begin();
            // }
            return binarySearch(nums, target, 0, pivot - 1);
        }
        return ans;
    }
};