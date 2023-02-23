//Cleaner Solution
int elementThatAppearsOnce(vector<int> arr) {
	// Write your code here.
	int bits[32]={0};
	int n = arr.size();
	int  val = 0;
	for (int i =0;i<31;i++){
		for (int j =0 ;j<n;j++){
			if((arr[j]>>i)&1){
				bits[i]++;
			}
		}
	val |= (bits[i]%3)*(1<<i);
}

return val;
}




int elementThatAppearsOnce(vector<int> arr) {
	// Write your code here.
	int n =arr.size();
	vector<int>bits(32,0);
       
	int mask = 1;
        for (int i=0;i<32;i++){
			for (int j =0;j<n;j++){
				if(mask&arr[j])
				bits[i]++;
			}
        
		mask = mask << 1;
        }

		for(auto &i:bits){
			if(i%3==0)
				i=0;
            else
                i = 1;
                }
		

		// for (auto i:bits)cout<<i<<" ";
		int maskbin = 1;
		long long  val=0;
		for (int i =0;i<32;i++){
			val+=bits[i]*maskbin;
			maskbin =maskbin<<1;
		}

		return val;

}