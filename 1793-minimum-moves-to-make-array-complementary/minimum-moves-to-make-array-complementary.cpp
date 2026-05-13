class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> pref(2 * limit + 2);
        for (int i = 0; i < n / 2; i++) {
            int mn = min(nums[i], nums[n - i - 1]);
            int mx = max(nums[i], nums[n - i - 1]);
            // case 1 (2 moves)
            pref[2] += 2;
            pref[2 * limit + 1] -= 2;
            // case 2 (1 move)
            pref[mn + 1] -= 1;
            pref[mx + limit + 1] += 1;
            // case 3 (0 move)
            pref[mn + mx] -= 1;
            pref[mn + mx + 1] += 1;
        }
        int sum = 0, minOps = n + 1;
        for(int i = 2; i <= 2 * limit; i++) {
            sum += pref[i];
            minOps = min(minOps, sum);
        }
        return minOps;
    }
};