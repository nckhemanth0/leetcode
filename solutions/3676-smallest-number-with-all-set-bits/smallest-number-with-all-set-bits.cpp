class Solution {
public:
    int smallestNumber(int n) {
        return pow(2,(int)log2(n)+1)-1;
    }

    // ===== ===== ====== ====== ======= ===== ===== ====== ====== =======

    // Time O(LogLogN) and Space O(1) where is the maximum
    // value of n.
    int smallestNumber__other_way(int n) {
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        return n;
    }
};