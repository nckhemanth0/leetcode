class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans="";
        for(auto x: strs){
            ans+=x;
            ans+='\n';
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        cout<<s<<endl;
        // ---> code do not work for multi charecter delimiter like "π"
        istringstream iss(s);
        string token;
        while(getline(iss,token,'\n')){
            ans.push_back(token);
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));