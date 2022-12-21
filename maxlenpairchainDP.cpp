// time complexity O(n^2)
// more complicated DP solution, inspired by cp-algorithms.com LIS solution
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n= pairs.size();
        vector<vector<int>>d(n+1);
        for (int i =0;i<=n;i++){
            d[i].push_back(INT_MAX);
            d[i].push_back(INT_MAX);

        }
        d[0][0]= INT_MIN;
        d[0][1]= INT_MIN;
        sort(pairs.begin(),pairs.end(),cmp);
        for (int i =0;i<n;i++){
            for (int j =1;j<=n;j++){
                if(d[j-1][1]<pairs[i][0] && pairs[i][1]<d[j][1]){
                    d[j]=pairs[i];
                }
            }
        }
        int len = 0;
        for (int i =0;i<=n;i++){
            if(d[i][0]!=INT_MAX){
                len = i;
            }
        }
    return len;
    // return 0;
    }

    static bool cmp(const vector<int> &a , const vector<int> &b){
        return a[1]<b[1];
    }
};