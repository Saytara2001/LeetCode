class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, best = INT_MIN;
        for(auto x: nums) {
            sum = max(x, sum + x);
            best = max(best, sum);
        }
        return best;
    }
};