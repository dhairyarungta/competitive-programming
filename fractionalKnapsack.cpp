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
bool cmp (pair<int,int> a , pair<int,int> b){
    float val1 =  ((float)a.first)/a.second;
    float val2 = ((float)b.first)/b.second;
    return val1>val2;
}
void solve (){
    int n ,w;
    cin>>n>>w;
    vector<pair<int,int>> v(n);
    // first denotes value , second denotes weight
    loop(i,n){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),cmp);
    double totalVal = 0;
    int i = 0;
    for ( i =0;i<n;i++){
        if (w>=v[i].second){
            w-=v[i].second;
            totalVal+=v[i].first;

        }
        else break;
    }
    if(i<n)
        totalVal += w*( ((double)v[i].first)/v[i].second);
    cout << totalVal << "\n";
}

int main(){
    fast_io;
    cout<<fixed;
    cout<< setprecision(6);
    precal();
    int t =1;
    // cin>> t ;
    for (int i =1;i<=t;i++){
        // cout<< "Case #"<<i<<": ";
        solve();
    }

    return 0;

}