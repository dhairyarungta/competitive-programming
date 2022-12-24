int lengthOfLongestSubstring(string s) {
    int n = s.size();
    vector<int>f(26,0);
    int start =0;
    int total =0;
    int maxLen = 0;
    for (int end =0;end<n;end++ ){
        if(f[s[end]-'a']==0){
            f[s[end]-'a']++;
            total++;
        }
        else {
            f[s[end]-'a']++;
        }

        if(total<=2) maxlen = max(maxlen, end-start+1);
        else{
            while(&& total>2){
                f[s[start]-'a']--;
                if(f[s[start]-'a']==0) total--;
                
                start++;                                                                            
            }
        }
    }
    cout << maxlen<<"\n";
}