/*
    Your Timebased object will be instantiated and called as such:

    Timebased* obj = new Timebased();
    obj->setKey(key,value,timestamp);
    string ans = obj->getValue(targetKey,targetTimestamp);
*/
#include <bits/stdc++.h>

class Timebased {
    public:
        map<string, map<int, string, greater<int>>> mp;

        Timebased() {
            // Intialise your data structure here.

        }

    void setKey(string key, string val, int timestamp) {
        // Write your code here.
        mp[key].insert({timestamp,val});
        
    }

    string getValue(string targetKey, int targetTimestamp) {
        // Write your code here.afd
        if (mp.count(targetKey)==0){
            return "-1";
        }
        else {
            // map<int, string>::iterator it = lower_bound(mp[targetKey].begin(),mp[targetKey].end(),targetTimestamp);
            map<int,string> ::iterator it = mp[targetKey].lower_bound(targetTimestamp);
            if (it!= mp[targetKey].end()) {
              return it->second;
            }

            else
              return "-1";
        }
        
    }
};