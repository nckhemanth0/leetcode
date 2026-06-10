// copied for streak at last min... clear and retry!!!!

class Solution {
public:

    bool isValid(string &s){
        if(s.size()==0){
            return false;
        }
        for(char c:s){
            if(!isalnum(c)&& c!='_'){
                return false;
            }
        }
        return true;
    }

    bool isValidBusiness(string &s){
        if(s=="electronics" || s=="grocery"|| s=="pharmacy"||s=="restaurant"){
            return true;
        }

        return false;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        
       map<string,multiset<string>> mp;
        int n = code.size();
        for(int i=0;i<n;i++){
            if(isActive[i]&&isValid(code[i]) &&isValidBusiness(businessLine[i]))
            mp[businessLine[i]].insert(code[i]);
        }

       

        vector<string> ans;
        for(auto i: mp){
            for(string j:i.second){
                ans.push_back(j);
            }
        }
        return ans;
    }
};