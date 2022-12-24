#include <bits/stdc++.h> 
int minProduct(vector<int> &arr, int n, int k) {
    // Write your code here.
    long long p = 1e9+7;
    sort(arr.begin(),arr.end());
    long long ans = 1;
    for(int i =0;i<k;i++)ans=(ans*arr[i])%p;
    return ans;
}