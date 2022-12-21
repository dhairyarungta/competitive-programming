//time complexity O(n^2)
//simple dp solution
//d[i] represents the len of maxlenpairchain considering elements from index 0 to i and terminating at  element pairs[i]
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int n = pairs.size();
        vector<int> d(n,1);

        for (int i =1;i<n;i++){
            int len = 1;
            for (int j = 0;j<i;j++){
                if (d[j]>=len && pairs[j][1]<pairs[i][0]){
                    len = d[j]+1;
                }
            }
            d[i]=len;
        }
        int maxlen = 1;
        for (int i =0;i<n;i++){
            if (d[i]>maxlen){
                maxlen = d[i];
            }
        }

        return maxlen;
    }

    static bool cmp (const vector<int> &a , const vector<int> &b){
        return a[1]<b[1];
        // return a[0]<b[0] both forms of sorting work and give same final max len
    }
};