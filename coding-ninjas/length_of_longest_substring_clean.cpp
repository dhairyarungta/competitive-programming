int lengthOfLongestSubstring(string s) {
    // Write your code here.
    // assuming that the string only contains lower case alphabets 

    vector<int> a(26,0);
    int n = s.size();
    int st= 0,e=0,maxLen=0;
    int numDistinct = 0;
    for(e=0;e<n;e++){
        int curLen = e-st+1;
        if(a[s[e]-'a']!=0){
          a[s[e] - 'a']++;
          maxLen = max(curLen,maxLen);   
        }
       else  if(a[s[e]-'a']==0 && numDistinct<2){
            numDistinct++;
            a[s[e]-'a']++;
            maxLen = max(curLen,maxLen);
        }
        else {
            a[s[e] - 'a']++;
            numDistinct++;

            while(numDistinct>2 && st<=e){
                --( a[s[st]-'a']);
               if((a[s[st]-'a'])==0){
                   numDistinct--;
               }
                ++st;
            }
        }
    }

    return maxLen;
}
