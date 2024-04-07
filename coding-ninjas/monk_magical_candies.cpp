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
    int n , k ;
    cin>>n>>k;
    priority_queue <ll>pq;
    fr(i,0,n){
        ll temp ;
        cin>>temp;
        // cout<<temp <<" ";
        pq.push(temp);
    }

    ll ans = 0;

    while(k--){

        if(pq.empty())
            break;
        
        ll curMax = pq.top();
        // cout<<curMax<<" ";
        pq.pop();
        ans+=curMax;
        pq.push(curMax>>1);

    }
    cout<<ans<<"\n";
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