class Solution {
public:

    vector<int> mentions;
    // could have directly tracked next online for each. initial next online is 0 for all
    unordered_map<int,int> offline;

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n=numberOfUsers;
        mentions.resize(n);
        sort(events.begin(),events.end(),[&](vector<string> a, vector<string> b){
            // did mistake => need to convert to integer before compare!
            int ta=stoi(a[1]), tb=stoi(b[1]);
            if(ta==tb){
                return a[0]>b[0];
            }
            return ta<tb;
        });
        for(int i=0;i<events.size();i++){
            int timestamp=stoi(events[i][1]);
            if(events[i][0]=="MESSAGE"){
                // process all offline. 
                string users=events[i][2];
                istringstream iss(users);
                string token;
                while (iss >> token) {
                    if(token=="ALL"){
                        // notify all
                        for(int i=0;i<n;i++){
                            mentions[i]++;
                        }  
                    }else if(token=="HERE"){
                        // notify online
                        for(int i=0;i<n;i++){
                            // update all pending offlines so far
                            if(offline.count(i) && offline[i]<timestamp){
                                offline.erase(i);
                            }
                            if(!offline.count(i)){
                                mentions[i]++;
                            }
                        }
                    }else{
                        int userId=stoi(token.substr(2));
                        mentions[userId]++;
                    }
                    
                }

            }else if(events[i][0]=="OFFLINE"){
                int userId=stoi(events[i][2]);
                offline[userId]=max(offline[userId],timestamp+59);
            }
        }
        return mentions;
    }
};

/*

2 events

all users initially online

MESSAGE => users who got mentioned at timestamp
OFFLINE => t to t+59 an user is offline and get online at t+60

return - each user - num of mentions of user

*/