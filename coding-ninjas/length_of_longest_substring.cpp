int lengthOfLongestSubstring(string s) {
    // Write your code here.
    int i =0, n = s.size(), j =0;
    char a ,b;
    if(n<=1)   
        return n;
    a = s[0];
    b = 0;
    int maxLen =1;
    int curLen=0;
    for (int i =0;i<n;i++){
     if(b==0 && s[i]!=a){
        b =s[i];
        curLen++;
        maxLen =max(curLen,maxLen);
    }
    else if (s[i]==a || s[i]==b){
        curLen++;
        maxLen =max(curLen,maxLen);
    }
    else {
        char c =s[i-1];
        char d = s[i];
        int k ;
        for (k=i-1;k>=0 && s[k]==c;k--) ;
        curLen = i-(k+1)+1;
        a = c ;
        b= d;
     }
    }
return maxLen;
}
