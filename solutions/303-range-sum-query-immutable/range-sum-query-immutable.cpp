class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums): prefix(nums) {
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        cout<<left<<" "<<right<<endl;
        return prefix[right]-((left-1>=0)?prefix[left-1]:0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */