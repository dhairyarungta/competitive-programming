#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
	int t ; cin>>t;
	while(t--){
	int num;
	cin >> num;    //Reading input from STDIN
	set<string>a;
	for (int i =0;i<num;i++){
		string temp ;
		cin>>temp;
		a.insert(temp);
	}
	for (auto i:a){
		cout<<i<<"\n";
	}
	}
}