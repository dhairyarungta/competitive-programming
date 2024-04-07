#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(i,a,b) for (int i =a;i<b;i++)
#define loop(x,n) for (int x = 0;x<n;++x)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()

using namespace std;

void precal(){

}

void solve (){
    int n ,target;
    cin>> n>>target;
    vector<int> a (n);
    for(int i =0;i<n;i++)cin>>a[i];

    // a is sorted according to question but still can uncomment the line if not (time complexity of sort O(n*logn))
    // sort(all(a));
    int start =0, end = n-1;
    
    //print the indexes of the elements that add to the target value or print -1 -1
    while (start<end){
        int curSum = a[start]+a[end];
        if(curSum==target) {
            cout<<start <<" "<<end<<"\n";
            return;
        }
        else if (curSum <target){
            start++;
        }
        else {
            end--;
        }
    }

    cout<<-1<<" "<<-1<<"\n";
    

}

int main(){
    fast_io;
    cout<<fixed;
    cout<< setprecision(10);
    precal();
    int t =1;
    // cin>> t ;
    for (int i =1;i<=t;i++){
        // cout<< "Case #"<<i<<": ";
        solve();
    }

    return 0;

}