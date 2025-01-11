class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = size(arr);
        vector<int> pref(n), suff(n);
        int maxSum = INT_MIN;

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
            pref[i] = sum;
        }

        if(maxSum < 0) 
            return maxSum;

        sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            sum += arr[i];
            if(sum < 0) sum = 0;
            suff[i] = sum;
        }

        
        for(int i = 0; i + 2 < n; i++) {
            maxSum = max(maxSum, pref[i] + suff[i + 2]);
        }

        return maxSum;
    }
};