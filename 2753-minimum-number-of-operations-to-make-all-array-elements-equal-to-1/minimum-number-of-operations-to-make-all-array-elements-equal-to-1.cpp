class Solution {
public:
    int minOperations(vector<int> &nums) {
        int gcd = 0, n = nums.size();
        int ones = 0;
        for (int i = 0; i < n; ++i) {
            ones += nums[i] == 1;
            gcd = __gcd(gcd, nums[i]);
        }

        if (gcd > 1)
            return -1;

          if (ones > 0)
            return n - ones;

        int ans = 2 * n;
        for (int i = 0; i < n; ++i) {
            gcd = 0;
            for (int j = i; j < n; ++j) {
                gcd = __gcd(gcd, nums[j]);
                if (gcd == 1) {
                    ans = min(ans, j - i);
                    break;
                }
            }
        }
        ans += n - 1;
        return ans;
    }
};