// O(n) Time Complexity 
#include <bits/stdc++.h>
    int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) {
    // Write your code here.
    int totalgas = 0;
    int totalcost= 0;

    for (auto i: gas)totalgas+=i;
    for(auto i:cost )totalcost+=i;

    if(totalcost > totalgas)return -1;

    int curgas = 0;
    int curcost = 0;
    int index =0 ;

    for (int i =0;i<n;i++){
      curgas += gas[i];
      if (curgas - cost[i] < 0) {
        index = i + 1;
        curgas = 0;
      }
       else {
         curgas-=cost[i];
      }
    }

  return index;
}
//Time Compelxity O(n^2)
// TLE error
int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) 
{
    // Write your code here.

    for (int i =0 ;i<n;i++){
        int curgas =0;
        int j =i;
        while(true){
            curgas+=gas[j];
            if(curgas<cost[j]){
                break;
            }
            else {
                curgas-=cost[j];
            }

            j++;
            j%=n;
            if(j==i){
                // cout<<i<<"\n";
                return i;
            }
        }
    }

    // cout<<-1<<"\n";
    return -1;
}