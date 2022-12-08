#include <bits/stdc++.h>

bool checkOverlappingIntervals(long* start, long* end, int n)
{
    //Write your code here 
    vector<pair<long,long>>t(n);
    for (int i =0;i<n;i++){
        t[i]= {start[i],end[i]};
    }
    sort(t.begin(),t.end());

    for(int i =1;i<n;i++){
        // cout << t[i].first<<" "<<t[i-1].second<<"\n";
        if (t[i].first<t[i-1].second)
            return true;

        
    }
return false;
}
