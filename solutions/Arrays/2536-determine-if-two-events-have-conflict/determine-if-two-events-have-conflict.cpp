class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if(event1[0]>event2[0]){
            swap(event1,event2);
        }
        if(event2[0]<=event1[1]){
            return true;
        }
        return false;
    }
};