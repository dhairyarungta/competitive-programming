long long int sumOfHammingDistance(int *arr, int n) {
    // Write your code here.
    long long  sum = 0;
    for (int i = 0;i<32;i++){
        int count = 0;
        int mask = 1<<i;
        for (int j = 0;j<n;j++){
            if(mask&arr[j])
            count++;
            
        }
        sum+=count*2*(n-count);
    }
return sum;
}