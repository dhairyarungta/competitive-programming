#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool compareFun(pair<string,int>const &a, pair<string,int> const &b){
	if(a.second==b.second){
		if(a.first.compare(0,b.first.size(),b.first)==0 || b.first.compare(0,a.first.size(),a.first)==0){
			return a.first.size()<b.first.size();
		}
		else return a.first<b.first;
	}
	else return a.second>b.second;
}

int main() {
	int num;
	cin >> num;    //Reading input from STDIN
	vector<pair<string,int>>a(num);
	for (int i =0;i<num;i++){
		cin>>a[i].first>>a[i].second;
	} 
	sort(a.begin(),a.end(),compareFun);

	for (int i =0;i<num;i++){
		cout<<a[i].first<<" "<<a[i].second<<"\n";
	} 

}