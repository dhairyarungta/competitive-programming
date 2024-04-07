#include <bits/stdc++.h>

bool cmp (const pair<double, int> &a , const pair<double, int> &b){
    if(a.first==b.first)return a.second <b.second;
    else return a.first<b.first ;
}

vector<int> minLoss(int n, vector<int> &time, vector<int> &loss) {
    // Write your code here.
    vector<int> vec(n,0);
    vector<pair <double,int>> ans(n);
    for (int i =0;i<n;i++){
        ans[i].first=((float)time[i])/loss[i] ;
        ans[i].second = i+1;

    }
    sort(ans.begin(),ans.end(),cmp);

    for (int i =0;i<n;i++){
        vec[i]= ans[i].second;

    }

    return vec;

    
}