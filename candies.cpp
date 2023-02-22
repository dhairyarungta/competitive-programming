int requiredCandies(vector < int > &students) {
    // Write your code here
    int n  =students.size();
    vector<int> ans(n,1);

    for (int i =1;i<n;i++){
        if(students[i]>students[i-1]){
            ans[i]+=ans[i-1];
        }
    }
    for (int i =n-2;i>=0;i--){
        if( ans[i]<ans[i+1]+1 && students[i]>students[i+1]){
            ans[i]=ans[i+1]+1;
        }
    }

    int sum=0;
    for (auto i :ans)sum+=i;
    return sum;
}