
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(i,a,b) for (ll i =a;i<b;i++)
#define loop(x,n) for (ll x = 0;x<n;++x)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()

using namespace std;

void precal(){

}

void solve (){
    ll n , m;
    cin>>n>>m;
    vector<ll> a(n);
    vector<ll> b(m);
    fr(i,0,n)cin>>a[i];
    fr(i,0,m)cin>>b[i];
    
    map <ll, ll> mp;
    for (ll i =0;i<n;i++){
        mp[a[i]]++;
    }
    for (ll i =0;i<m;i++){

        if(mp[b[i]]==0){

            cout<<"NO"<<"\n";
            mp[b[i]]++;

        }
        else {
            cout<<"YES"<<"\n";
            mp[b[i]]++;

        }
    }

}

int main(){
    fast_io;
    cout<<fixed;
    cout<< setprecision(10);
    precal();
    ll t =1;
    cin>> t ;
    for (ll i =1;i<=t;i++){
        // cout<< "Case #"<<i<<": ";
        solve();
    }

    return 0;

}