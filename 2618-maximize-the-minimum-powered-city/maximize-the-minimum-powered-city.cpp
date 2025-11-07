class Solution {
public:
    long long maxPower(vector<int> &stations, int r, int k) {
        int n = stations.size();
        vector<long long> pref(n + 2);
        for (int i = 1; i <= n; i++) {
            int left = max(1, i - r);
            int right = min(n, i + r);
            pref[left] += stations[i - 1];
            pref[right + 1] -= stations[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            pref[i] += pref[i - 1];
        }
        auto valid = [&](long long mid) -> bool {
            int powers = k;
            long long bonus = 0;
            queue<pair<int, long long> > q; // idx, power_added
            for (int i = 1; i <= n; i++) {
                while (q.size() and abs(q.front().first - i) > r) {
                    bonus -= q.front().second;
                    q.pop();
                }
                long long cur = pref[i] + bonus;
                if (mid > cur) {
                    // need to add more
                    long long neededToAdd = mid - cur;
                    if (powers >= neededToAdd) {
                        powers -= neededToAdd;
                        int farthest = min(n, i + r);
                        q.push({farthest, neededToAdd});
                        bonus += neededToAdd;
                    } else {
                        return false;
                    }
                }
            }
            return true;
        };
        long long left = 0, right = 1e16;
        while (left < right) {
            long long mid = left + (right - left + 1) / 2;
            if (valid(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};