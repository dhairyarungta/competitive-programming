#include <bits/stdc++.h>

// this the brute force solution to the "Maximum length pair chain" Problem
bool isValid(vector<pair<int,int>> &sol, pair<int, int> p ){
    int i =0;
    for (;i<sol.size();i++){
        if(p.second<sol[i].first)
            break;
    }
    if (i==0)
        return true;

    else {
        if (p.first>sol[i-1].second){
            return true;
        }
        else {
            return false;
        }
    }
}

void insertPair(vector<pair<int,int>> & sol , pair<int, int> p){
    //     cout<<endl;
    // for (int i =0;i<sol.size();i++) cout<<sol[i].first<<","<<sol[i].second<<" ";
    // cout<<endl;

    int i =0;
    for (;i<sol.size();i++){
        if (p.second<sol[i].first){
            break;
        }
    }
    sol.insert(sol.begin()+i,p);
    // cout<<endl;`
    // for (int i =0;i<sol.size();i++) cout<<sol[i].first<<","<<sol[i].second<<" ";
    // cout<<endl;
}

int recSol(vector<pair<int, int>> &p , vector< pair<int, int>> sol , int n ){
    if (n == 0){
        return 0;
    }

    pair<int, int> curPair = p[0];
    if (isValid(sol,curPair)){
        vector<pair<int, int>> newSol (sol.size());
        for (int i =0;i<sol.size();i++) newSol[i]= sol[i];
        insertPair(newSol,curPair);
        vector<pair<int, int>>temp(p.size()-1);
        for (int i =1;i<n;i++) temp[i-1]= p[i];
        int ans1 = recSol(temp,sol, n-1);
        int ans2 = recSol(temp,newSol,n-1)+1;
        return max(ans1,ans2);
    }
    else {
        vector<pair<int, int>>temp(p.size()-1);
        for (int i =1;i<n;i++) temp[i-1]= p[i];
        int ans1 = recSol(temp,sol, n-1);
        return ans1;
    }

}


int maxLengthChain(vector<pair<int, int>> &p, int n) {
    // Write your code here.
    vector <pair<int, int>> sol ;
    return recSol(p,sol,n);
}