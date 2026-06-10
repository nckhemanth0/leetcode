class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int x1=0,x2=0;
        for(auto x:s){
            if(x=='a'){
                x1++;
            }else{
                x2++;
            }
        }
        return s.size()-2*min(x1,x2);
    }
};