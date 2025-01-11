class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = size(arr);
        vector<int> pref(n), suff(n);
        int maxSum = INT_MIN;

        int sum = 0, minSum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            pref[i] = sum - minSum;
            minSum = min(minSum, sum);
            maxSum = max(maxSum, pref[i]);
        }

        sum = 0, minSum = 0;
        for(int i = n - 1; i >= 0; i--) {
            sum += arr[i];
            suff[i] = sum - minSum;
            minSum = min(minSum, sum);
        }

        
        for(int i = 0; i + 2 < n; i++) {
            maxSum = max(maxSum, pref[i] + suff[i + 2]);
        }

        return maxSum;
    }
};