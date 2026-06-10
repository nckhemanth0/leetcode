class Solution {
public:
    vector<vector<int>> ans;

    void rec__looping(vector<int> v, int target, int level, vector<int> list){
        //base
        if(level==v.size()){
            if(target==0){
                ans.push_back(list);
            }
            return;
        }
        //all cases:
        for(int itr=0;itr<=(target/v[level]);itr++){
            for(int i=0;i<itr;i++){
                list.push_back(v[level]);
            }
            rec(v,target-(v[level]*itr),level+1,list);
            for(int i=0;i<itr;i++){
                list.pop_back();
            }
        }
    }

    void rec(vector<int> v, int target, int level, vector<int> list){
        //base
        if(level==v.size()){
            if(target==0){
                ans.push_back(list);
            }
            return;
        }
        //take
        if(v[level]<=target){ // or no need this case if we add a pruning step to eliminate target<0 cases
            list.push_back(v[level]);
            rec(v,target-v[level],level,list);
            list.pop_back();
        }
        //not take
        rec(v,target,level+1,list);
    }

    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        vector<int> list;
        rec__looping(v,target,0,list);
        return ans;
    }
};