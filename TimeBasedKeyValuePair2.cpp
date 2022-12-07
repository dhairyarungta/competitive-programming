/*
    Your Timebased object will be instantiated and called as such:

    Timebased* obj = new Timebased();
    obj->setKey(key,value,timestamp);
    string ans = obj->getValue(targetKey,targetTimestamp);
*/
#include <map>
class Timebased {
    public:
        
    map<string,map<int,string,greater<int>>>mp;

    void setKey(string key, string val, int timestamp) {
        // Write your code here.
    // mp[key].insert({timestamp,val});
    mp[key][timestamp]= val;

    }

    string getValue(string targetKey, int targetTimestamp) {
        // Write your code here.
    if (mp.count(targetKey)==0)
    return "-1";

    else {
        auto it = mp[targetKey].lower_bound(targetTimestamp);
        if (it==mp[targetKey].end()){
            return "-1";
        }

        else {
            return it->second;
        }
    }

    }
};