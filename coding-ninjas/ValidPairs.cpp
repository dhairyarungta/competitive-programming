bool CheckSumPairs(int ar[], int n, int k, int m) {
	/*Write your code here. 
	*Don't write main().
	*Don't take input, it is passed as function argument.
	*Don't print output.
	*Taking input and printing output is handled automatically.
	*/ 
	map <int, int> mp ;
	if(n%2 == 1)
		false;

	for (int i =0;i<n;i++){
		if(mp.count(ar[i]%k)==0){
			mp[ar[i]%k]=1;
		}
		else {
			mp[ar[i]%k]++;

		}
	}


	map < int, int> ::iterator it ;
	for (it = mp.begin();it!=mp.end();it++){
		int num = it->first ;
		if ((2*num) == m &&( (mp[num])%2==1))
			return false;
		else if (mp[num]!= mp[(m-num+k)%k])
			return false;

	}
	return true;
