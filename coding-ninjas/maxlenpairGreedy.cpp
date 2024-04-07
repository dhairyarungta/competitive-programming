#include <bits/stdc++.h>

bool cmp (pair<int, int> a , pair<int,int> b) {
    return (a.second<b.second);
    
}
int maxLengthChain(vector<pair<int, int>> &p, int n) {
    // Write your code here.


    sort(p.begin(),p.end(),cmp );
    int len = 1;
    pair<int, int> lastPair= p[0];
    for (int i =1;i<n;i++){
        if (p[i].first>lastPair.second){
            len++;
            lastPair =  p[i];
        }
    }

    return len;
    // return 0;
}