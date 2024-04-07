#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back`
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
    int n ;
    cin>> n;
    vector<int> v(n);
    fr(i,0,n) cin>>v[i];
    sort(all(v));
    int min = 2e9+69;
    for (int i =1;i<n;i++){
        if(min>(v[i]-v[i-1])){
            min = v[i]-v[i-1];
        }
    }
    cout << min<<"\n";
}

int main(){
    fast_io;
    cout<<fixed;
    cout<< setprecision(10);
    precal();
    int t =1;
    cin>> t ;
    for (int i =1;i<=t;i++){
        // cout<< "Case #"<<i<<": ";
        solve();
    }

    return 0;

}