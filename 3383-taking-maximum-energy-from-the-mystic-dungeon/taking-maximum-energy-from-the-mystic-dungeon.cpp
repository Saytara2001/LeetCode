class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);
        int max_energy = INT_MIN;
        for(int i = 0; i < n; i++) {
            dp[i] = energy[i];
            if(i - k >= 0) {
                dp[i] = max(dp[i] + dp[i - k], dp[i]);
            }
            if(i >= n - k)
                max_energy = max(max_energy, dp[i]);
        }
        return max_energy;
    }
};