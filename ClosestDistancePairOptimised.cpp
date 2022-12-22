#include <bits/stdc++.h>

bool compareX ( pair<int, int> a ,  pair<int, int> b){
    return (a.first<b.first) || (a.first==b.first && a.second<b.second) ;
}

bool compareY( pair <int, int> a ,  pair< int, int>  b){
  return (a.second < b.second) || (a.second == b.second && a.first < b.first);
}

long calDistance(const pair<int, int>&a , const pair<int, int> &b){
    long dist1 =  (long)(a.first-b.first);
    long dist2 = (long)(a.second-b.second);

    return (dist1*dist1)+(dist2*dist2);
}

long bruteforceSol(pair<int,int> * coordinates, int n){
    long mindist = INT64_MAX;
    for (int i =0;i<n;i++){
        for (int j =i+1;j<n;j++){
            if(calDistance(coordinates[i],coordinates[j])<mindist){
                mindist= calDistance(coordinates[i],coordinates[j]);
            }
        }
    }
    return mindist;
}

long stripClosest(pair<int,int>* strip , int size, long dist){

    long minDist = dist;
    for (int i =0;i<size;i++){
        for (int j =i+1; j<size && ((strip[j].second -strip[i].second)<minDist);j++){
            if (calDistance(strip[i],strip[j])<minDist){
                minDist = calDistance(strip[i],strip[j]);
            }
        }
    }
    // cout << minDist <<" ";
    return minDist;
}

long recursvieClosestPair(pair<int, int> * xSorted, pair<int,int>*ySorted, int n){
    if (n<=3){
        return bruteforceSol(xSorted,n);
    }

    int mid = (n-1)>>1;
    pair<int,int> midPoint = xSorted[mid];
    pair<int,int>* yleftSorted = new pair<int,int>[mid+1];
    pair<int,int>* yrightSorted = new pair<int,int>[n-mid-1];
    int li =0, ri = 0;

    for (int i=0;i<n;i++){
        if((ySorted[i].first<midPoint.first || (ySorted[i].first==midPoint.first && ySorted[i].second<=midPoint.second ))&& li<=mid)
            yleftSorted[li++]=ySorted[i];
        else 
            yrightSorted[ri++]= ySorted[i];
    }

    
    long ans1 = recursvieClosestPair(xSorted,yleftSorted,mid+1);
    long ans2 = recursvieClosestPair(xSorted+mid+1,yrightSorted,n-mid-1);

    long overallAns = min(ans1,ans2);

    pair<int,int> *strip= new pair<int,int>[n];
    for (int i =0;i<n;i++){
        strip[i].first =0;
        strip[i].second =0;
    }
    int j =0;
    for (int i =0;i<n;i++){
        if(abs(ySorted[i].first-midPoint.first)<(overallAns)){
            strip[j]=ySorted[i];
            j++;
        }
    }
    // j now contains the size of the strip array
    long ansreturn =  stripClosest(strip,j,overallAns);
    delete []yleftSorted;
    delete []yrightSorted;
    delete []strip;
    return ansreturn;
}

long closestPair(pair<int, int>* coordinates, int n)
{
    //Write your code here
    pair<int,int>* ySorted = new pair<int, int>[n];
    for (int i =0;i<n;i++) ySorted[i]= coordinates[i];

    sort(coordinates,coordinates+n,compareX);
    sort(ySorted,ySorted+n,compareY);
    return recursvieClosestPair(coordinates, ySorted, n);
    // return 0;
}`