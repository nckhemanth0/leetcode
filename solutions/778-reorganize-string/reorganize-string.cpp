class Solution {
public:

    // optimization... we dont need to put 2nd max, 3rd max,... after 1st max.
    /*
        a a a a d => a-4, b we know <=4
        abababadb => here by the time b goes adjacent to 1st b, it completes since it's cnt <= of a
        so whenever we kwwp 2nd max doesnt matter
    */
    string reorganizeString(string s) {
        int n=s.size();
        vector<int> v(26,0);
        for(auto x: s){
            v[x-'a']++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<26;i++){
            pq.push({v[i],i});
        }
        int cnt=0;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            while(cnt%2==0 && x.first>0 && cnt<n){
                s[cnt]=x.second+'a';
                x.first--;
                cnt+=2;
            }
            if(cnt%2==0 && cnt>=n){
                cnt=1;
            }
            while(cnt%2==1 && x.first>0 && cnt<n){
                if(s[cnt-1]==x.second+'a'){
                    return "";
                }
                s[cnt]=x.second+'a';
                x.first--;
                cnt+=2;
            }
        }
        return s;
    }
};