//Time Complexity for this solution 
//is O(n(log_n)^2)

#include <bits/stdc++.h>
using namespace std;
bool compareX (const pair<int, int> &a, const pair <int,int> &b){
    return (a.first < b.first);
}
bool comapreY( const pair <int, int>& a, const pair <int, int>& b){
    return (a.second <b.second);
}

long long  calDistance (const pair<int, int> a , const pair <int, int>b ){
    // cout << " a :"<<a.first <<" "<<a.second<<endl;
    // cout << " b :"<<b.first <<" "<<b.second<<endl;

    long long  ans =  ((long)(a.first-b.first)*(long)(a.first-b.first))+((long)(a.second-b.second)*(long)(a.second-b.second));
        //  cout <<ans<<"\n";
     return ans ;

}

long long  bruteForceSol(pair<int,int> * coordinates, int n){
    long long  mindist = INT_MAX ;
    for (int i = 0 ; i<n;i++ ){
        for (int j = i+1;j<n;j++){
            if (mindist> calDistance(coordinates[i],coordinates[j])){
                mindist = calDistance(coordinates[i],coordinates[j]);
            }
        }
    }
    return mindist;
}
long long  closestPairStrip(vector<pair<int, int>>temp , int  j , long long  mindist){
    // for (int i =0;i<j;i++)
    //     cout<< temp[i].first<<","<<temp[i].second<<"    ";
    // cout << endl;

    sort (temp.begin(),temp.begin()+j, comapreY);

    // for (int i =0;i<j;i++)
    //     cout<< temp[i].first<<","<<temp[i].second<<"    ";
    // cout << endl;

    for (int i =0;i<j;i++){
        //  cout <<"i: "<< i<< endl;

        for (int k =i+1;k<j && (temp[k].second-temp[i].second)<mindist ;k++){
        //  cout <<"k: "<< k<< endl;
        //  cout <<"j: "<< j<< endl;
        //     cout << "indisde pairstrip function"<<"\n";
            if (calDistance(temp[i],temp[k])<mindist){
                
                mindist = calDistance(temp[i],temp[k]);
            }
        }
    }
    return mindist;
}


long long  recursiveUtilFunction(pair<int,int> * coordinates, int n){
    // return 0;
    if (n<=3){
        return bruteForceSol(coordinates, n);
    }
    int mid = (n-1)>>1;
    pair <int, int>  midPoint  = coordinates[mid];
    long long  mindist1 = recursiveUtilFunction(coordinates, mid+1);
    long long  mindist2 = recursiveUtilFunction(coordinates+mid+ 1, n-(mid+1));

    long long  mindist = min(mindist1,mindist2);
    vector < pair<int, int>> temp (n);
    // copy (coordinates, coordinates+n, temp.begin());
    int j = 0;

    for (int i =0;i<n;i++){
        if( abs(coordinates[i].first - midPoint.first)<mindist){
            temp[j++]= coordinates[i];
        
        }
    }

    return min(mindist, closestPairStrip (temp, j,mindist ));
}


long long  closestPair(pair<int, int>* coordinates, int n)
{ 
    //Write your code here
    sort (coordinates, coordinates+n,comapreX);
    return  recursiveUtilFunction(coordinates, n);
    
}