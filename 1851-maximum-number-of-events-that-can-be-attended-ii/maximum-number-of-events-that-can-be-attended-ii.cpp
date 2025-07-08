class Solution {
public:
    int rec(int i, int rem, vector<vector<int>> &events, vector<vector<int>> &dp) {
        if (i == events.size() or rem == 0)
            return 0;

        int &ret = dp[i][rem];
        if (~ret)
            return ret;

        ret = max(ret, rec(i + 1, rem, events, dp)); // leave

        // vector<int> need{events[i][1], 0, 0};
        auto nxt = greater(events, events[i][1]);
        ret = max(ret, rec(nxt, rem - 1, events, dp) + events[i][2]); // take
        return ret;
    }
    int greater(vector<vector<int>> &events, int target) {
        int left = 0, right = events.size() - 1;
        int ans = events.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (events[mid][0] <= target) {
                left = mid + 1;
            } else {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }
    int maxValue(vector<vector<int>> &events, int k) {
        int n = events.size();
        std::sort(events.begin(), events.end());
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return rec(0, k, events, dp);
    }
};