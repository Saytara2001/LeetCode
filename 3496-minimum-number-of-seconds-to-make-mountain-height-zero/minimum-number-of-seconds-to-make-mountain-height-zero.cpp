class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes) {
        int n = workerTimes.size();
        auto valid = [&](long long mid)-> bool {
            int cur = mountainHeight;
            for (int i = 0; i < n; ++i) {
                long long y = mid / workerTimes[i];
                long long x = (-1 + (sqrt(1 + 8 * y))) / 2;
                cur -= max(x, 0LL);
                if (cur <= 0) return true;
            }
            return cur <= 0;
        };
        long long l = 1, r = 1e18;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (valid(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};
