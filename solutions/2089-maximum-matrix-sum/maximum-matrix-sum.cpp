class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // get num of -'s
        // get minimum element
        long long n=matrix.size(), mini=1e5+1, sum=0, cnt_neg=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    cnt_neg=(cnt_neg+1)%2;
                }
                mini=min(mini,abs(1LL*matrix[i][j]));
                sum+=abs(matrix[i][j]);
            }
        }
        if(cnt_neg==0){
            return sum;
        }else{
            return sum-2*mini;
        }
    }
};