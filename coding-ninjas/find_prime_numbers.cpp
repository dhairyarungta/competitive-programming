//using sieve of eratosthenes

vector<int> primeNumbersTillN(int N) 
{ 
 	// Write your code here
	int arr[N+1]={0};
	//if arr[i] ==1 , then number is not prime
	arr[1]=1;

	for (int i =2;i*i<N;i++){
		if(arr[i]==1){
			continue;
		}
		for (int j = i*i;j<=N;j+=i){
			if(arr[j]==1){
				continue;
			}
			else if(j%i==0){
				arr[j]=1;
			}
		}
	}
	vector<int> vec;
	for (int i =2;i<=N;i++){
		if(arr[i]==0)vec.push_back(i);
	}
	return vec;
}