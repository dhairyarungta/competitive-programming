#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define pb push_back
#define fast_io                                                                \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define fr(i, a, b) for (int i = a; i < b; i++)
#define loop(x, n) for (int x = 0; x < n; ++x)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()

using namespace std;

void precal() {}

void solve() {
    int n;
    cin>>n;

    int val = n%4;
    if(val ==0){
        cout<<n<<"\n";
    }
    else if (val ==1){
        cout<<1<<"\n";
    }
    else if(val ==2){
        cout<<n+1<<"\n";

    }
    else cout<<0<<"\n";

}

int main() {
  fast_io;
  cout << fixed;
  cout << setprecision(10);
  precal();
  int t = 1;
  cin>> t ;
  for (int i = 1; i <= t; i++) {
    // cout<< "Case #"<<i<<": ";
    solve();
  }

  return 0;
}