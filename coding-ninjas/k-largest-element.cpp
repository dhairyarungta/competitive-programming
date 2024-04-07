#include <bits/stdc++.h>

vector<int> kLargest(int arr[], int n, int k) {
    // Write your code here
    vector <int> output ;
    priority_queue <int> pq;
    for (int i =0;i<n;i++){
        pq.push(arr[i]);
    }

    for (int i =0;i<k;i++){
        output.push_back(pq.top());
        pq.pop();
    }

    return output;
}