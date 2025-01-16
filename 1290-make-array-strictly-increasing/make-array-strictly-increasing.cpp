class Solution {
public:
    int dp[2000][2001][2];
    int rec(int i, int lstIdx, int fromAbove, vector<int>& arr1, vector<int>& arr2) {

        if(i == size(arr1))
            return 0;

        int &ret = dp[i][lstIdx][fromAbove];
        if(~ret)
            return ret;

        ret = 1e9;
        if(lstIdx == 2e3) {
            ret = min(ret, rec(i + 1, 0, 1, arr1, arr2)); // don't change
            ret = min(ret, rec(i + 1, 0, 0, arr1, arr2) + 1); // change
        }else {
            int prevValue = fromAbove ? arr1[lstIdx] : arr2[lstIdx];
            if(arr1[i] > prevValue) {
                // try to take or leave
                auto idx = upper_bound(begin(arr2), end(arr2), prevValue) - begin(arr2);
                if(idx < size(arr2)) {
                    ret = min(ret, rec(i + 1, idx, 0, arr1, arr2) + 1); // take
                }
                ret = min(ret, rec(i + 1, i, 1, arr1, arr2)); // leave
            } else {
                // must to take
                 auto idx = upper_bound(begin(arr2), end(arr2), prevValue) - begin(arr2);
                 if(idx < size(arr2)) {
                     ret = min(ret, rec(i + 1, idx, 0, arr1, arr2) + 1); // take
                 } else {
                    return 1e9;
                 }
            }
        }

        return ret;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        memset(dp, -1, sizeof dp);
        sort(begin(arr2), end(arr2));
        int res = rec(0, 2e3, 0, arr1, arr2); 
        return res == 1e9 ? -1 : res;
    }
};