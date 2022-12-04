#include <bits/stdc++.h>

pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
	// Write your code here
	sort (arr.begin(),arr.end());
        if (lower_bound(arr.begin(), arr.end(), x) != arr.end() && *(lower_bound(arr.begin(), arr.end(), x))==x) {
          return {lower_bound(arr.begin(), arr.end(), x) - arr.begin(),
                  upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1};
        } else
          return {-1, -1};
}

