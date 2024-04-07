#include<bits/stdc++.h>
//O(n) time complexity solution
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.

    int arr[2361]={0};
    for (int i =0;i<n;i++){
        arr[at[i]]++;
        arr[dt[i]+1]--;

    }
    int maxval = INT_MIN;
    for (int i =1;i<=2361;i++){
        arr[i]= arr[i]+arr[i-1];
        maxval= max(maxval,arr[i]);
    }

    return maxval;
}

//O(nlgn) timecompelxity 
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    vector<pair<int,int>> vec(n);
    for (int i =0;i<n;i++){
        vec[i].first= at[i];
        vec[i].second = dt[i];

    }
    sort(vec.begin(),vec.end());
    priority_queue<int,vector<int> ,greater<int>> pq;
    pq.push(vec[0].second);
    int count = 1;
    int maxcount = 1;
    for (int i =1;i<n;i++){
        if(vec[i].first<pq.top()){
            pq.push(vec[i].second);
            count++;
        }
        else {
            pq.pop();
            pq.push(vec[i].second);
        }

        maxcount= max(maxcount, count);
    }

    return maxcount ;
}