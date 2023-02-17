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

bool comp(const pair<int,int> & a, const pair <int, int> &b){
    return a.first>b.first;
}


void solve (){
    int n, k;
    cin>>n>>k;
    vector<pair<int,int>>vec(n);
    for (auto &[i,j]:vec){
        cin>>j;
        cin>>i;
    }
    //first element depicts value
    //vector pair (value, mass);
    
    // vector<int>a(k);
    // for (auto &i:a)cin>>i;
    // sort(a.begin(),a.end());

    multiset<int> a;
    for (int i =0;i<k;i++){
        int temp ;
        cin>>temp;
        a.insert(temp);
    }

    sort(vec.begin(),vec.end(),comp);
    // for(auto [i,j]:vec)cout<<i<<" ";
    int maxval = 0;
    for (int i =0;i<n;i++){
        auto iter = a.lower_bound(vec[i].second);
        if(iter!=a.end()){
            maxval+=vec[i].first;
            a.erase(iter);
        }
    }
    cout<<maxval<<"\n";

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