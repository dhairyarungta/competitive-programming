vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
    // Write your code here.
    // set  from 1 to n 
    int n = nums.size();
    int numsxor =0;
    for (auto i: nums)numsxor^= i;

    int perfectxor = 0;   
    for (int i =1 ;i<=n;i++)perfectxor^=i;

    int bothxor = perfectxor^numsxor;

    //find the last set bit in bothxor 
    int index = bothxor&(~(bothxor-1));

    int setindex =0;
    int notsetindex= 0;
    

    for (int i =0;i<n;i++){
        if(nums[i]&index)setindex^=nums[i];
        else notsetindex^=nums[i];

        if((i+1)&index)setindex^=(i+1);
        else notsetindex ^=(i+1);
    }
    for(auto i : nums){
        if(i==setindex){
            return vector<int> {i,i^bothxor};
        }
    }
    return vector<int> { notsetindex, setindex };
}