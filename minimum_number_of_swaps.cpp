#include <bits/stdc++.h>

int minSwap (int N, int M, int K, string &S, vector<char> &swaparr)
{
    int lookup[26]={0};
    for(auto i:swaparr){
        lookup[i-'a']=1;
    }


    int arr[K][26];
    for (int i =0;i<K;i++){
        for (int j =0;j<26;j++){
            arr[i][j]=0;
        }
    }
    
    for (int i = 0; i <N;i++){
        int rowindex = (i%K);
        arr[rowindex][S[i]-'a']++;
    }

    // for (int i = 0; i < K; i++) {
    //   for (int j = 0; j < 26; j++) {
    //     cout<< arr[i][j] <<" ";
    //   }
    //   cout<<endl;
    // }

    int ans = 0;
    for (int i =0;i<K;i++){
      int val = *max_element(arr[i], arr[i] + 26);
      int sum= 0;
      for (int j =0;j<26;j++){
        sum+=arr[i][j];
      }
      ans += (sum- val);
    }
    return ans;
}