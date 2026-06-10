class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto x: nums){
            mp[x]++;
            if(mp[x]>(n/2)){
                return x;
            }
        }
        return -1;
    }

    // ========= BITWISE SOL: 32*n Bitwise intuitive solution  =========

    /*
                class Solution {
                public:
                    int majorityElement(vector<int>& nums) {
                        int n = nums.size();
                        int majority_element = 0;

                        for (int i = 0; i < 32; i++) {
                            int bit = 1 << i;

                            // Count how many numbers have this bit set.
                            int bit_count = 0;
                            for (int num : nums) {
                                if ((num & bit) != 0) {
                                    bit_count++;
                                }
                            }

                            // If this bit is present in more than n / 2 elements
                            // then it must be set in the majority element.
                            if (bit_count > n / 2) {
                                majority_element |= bit;
                            }
                        }

                        return majority_element;
                    }
                };
    */
    

    // ========= BITWISE SOL: 32*n Bitwise intuitive solution  =========

    /*
                class Solution {
                public:
                    int countInRange(vector<int>& nums, int num, int lo, int hi) {
                        int count = 0;
                        for (int i = lo; i <= hi; i++) {
                            if (nums[i] == num) {
                                count++;
                            }
                        }
                        return count;
                    }

                    int majorityElementRec(vector<int>& nums, int lo, int hi) {
                        if (lo == hi) {
                            return nums[lo];
                        }

                        int mid = (hi - lo) / 2 + lo;
                        int left = majorityElementRec(nums, lo, mid);
                        int right = majorityElementRec(nums, mid + 1, hi);

                        if (left == right) {
                            return left;
                        }

                        int leftCount = countInRange(nums, left, lo, hi);
                        int rightCount = countInRange(nums, right, lo, hi);

                        return leftCount > rightCount ? left : right;
                    }

                    int majorityElement(vector<int>& nums) {
                        return majorityElementRec(nums, 0, nums.size() - 1);
                    }
                };
    */

    /*
            Just idea why x works:
                Why it Works (Intuition):
                    ans exisits for sure is given (so general patter we can assume one ans later unconsider it!)
                    Whenever count hits 0, it means:
                        We’ve seen equal numbers of candidate and non-candidate elements.
                        We can safely ignore that prefix
    */
};