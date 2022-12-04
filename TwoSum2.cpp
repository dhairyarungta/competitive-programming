#include <map>
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	// Write your code here. 
    vector <pair<int,int>> out;
    multimap<int, int> mp;

    for (int i =0;i<n;i++){
        mp.insert(pair<int,int>(arr[i],i));
    }
    
    for (multimap<int,int>::iterator it = mp.begin();it!=mp.end();){
		int num1 =it->first ;
        if (mp.find(target-num1)!=mp.end() && mp.find(target-num1)!=it){

            out.push_back(pair<int,int>(num1,target-num1));
            multimap<int,int>::iterator temp = it;
            it++;
            
            mp.erase(temp);
            // temp = mp.find(target-num1);
            // mp.erase(temp);
            mp.erase(mp.find(target-num1));
            
        }
        else it++;
    }
    
    
    if (out.empty())
        out.push_back(pair<int,int>(-1,-1));
    
    return out;
}
