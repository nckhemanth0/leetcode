/*
   initial missed cases: 
        duplicates
        if col=1 we are deleted, we have to only check col=2 where rows having in col=0 (not col=1) is same
        previous handling
            ["xga","xfb","yfa"]
            ["abx","agz","bgc","bfc"]
*/
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rs=strs.size();
        int cs=strs[0].size();
        vector<int> prev_same(rs,1); // initially -1th index all same
        int count_needed=rs-1; // initially -1th index all same
        int ans=0;
        for(int c=0;c<cs;c++){
            int count=0,equal=0;
            vector<int> is_same=prev_same;
            for(int r=1;r<rs;r++){
                if(prev_same[r]){
                    if(strs[r-1][c]<strs[r][c]){
                        is_same[r]=0;
                        count++;
                    }else if(strs[r-1][c]==strs[r][c]){
                        count++;
                        equal++;
                    }
                }
            }
            if(count==count_needed){
                if(equal!=0){
                    count_needed=equal; // needed should be updated after 1 cycle
                    prev_same=is_same;
                    continue;
                }
                return ans;
            }else{
                // count_needed=equal;
                ans++;
            }
        }
        return ans;
    }

    int minDeletionSize__clean_code_my_same_approach(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> sorted(n - 1, false);
        int deletions = 0;
        for (int col = 0; col < m; col++) {
            bool bad = false;
            // check violation
            for (int row = 0; row < n - 1; row++) {
                if (!sorted[row] && strs[row][col] > strs[row + 1][col]) {
                    bad = true;
                    break;
                }
            }
            if (bad) {
                deletions++;
                continue;
            }
            // update sorted pairs
            for (int row = 0; row < n - 1; row++) {
                if (!sorted[row] && strs[row][col] < strs[row + 1][col]) {
                    sorted[row] = true;
                }
            }
        }
        return deletions;
    }
};

/*
    editoial unoptimized: doing the same comparisons repeatedly on longer and longer strings → m times extra factor.

        class Solution {
        public:
            bool check(vector<string>& v){
                int n = v.size();
                for(int i=0;i<n-1;i++){
                    if(v[i] > v[i+1]){
                        return false;
                    }
                }
                return true;
            }

            int minDeletionSize(vector<string>& strs) {
                int count = 0;
                int m = strs[0].size();
                int n = strs.size();
                vector<string> prev(n, "");

                for(int i=0;i<m;i++){
                    vector<string> curr = prev;
                    for(int j=0;j<n;j++){
                        curr[j] += strs[j][i];
                    }
                    if(check(curr)){
                        prev = curr;
                    }else{
                        count++;
                    }
                }
                return count;
            }
        };

*/