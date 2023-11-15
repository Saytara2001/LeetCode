class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int mx = 1, n = size(arr);
        for(int i = 0; i < n; i++) {
            if(arr[i] < mx)
                continue;
            mx++;
        }
        return mx - 1;
    }
};