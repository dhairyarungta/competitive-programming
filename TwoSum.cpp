#include <map>

vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	// Write your code here. 
	 vector <pair <int, int>> output;
	 map<int, int> mp;
	 for (int i =0;i<n;i++){
		 mp[arr[i]]++;

	 }

	 for (int i =0;i<n;i++){
		 if ((2*arr[i])==target ){
		 	if (mp[arr[i]]>1){
			 output.push_back({arr[i],arr[i]});
			 mp[arr[i]]=mp[arr[i]]-2;
			 }
		 }

		 else if (mp[target-arr[i]]>0 && mp[arr[i]]>0){
			 output.push_back({arr[i],target-arr[i]});
			 mp[arr[i]]--;
			 mp[target-arr[i]]--;
			 


		 }
	 }
if (output.empty()){
	output.push_back({-1,-1});

}

return output;

}
