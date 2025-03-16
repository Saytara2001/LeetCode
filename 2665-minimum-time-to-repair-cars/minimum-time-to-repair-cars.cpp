class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = size(ranks);
        auto valid = [&](long long time) {
            int have = cars;
            for(int i = 0; i < n; i++) {
                long long repairedCars = sqrtl(time / ranks[i]);
                have -= repairedCars;
                if(have <= 0) return true;
            }
            return false;
        };
        long long l = 1, r = 1e15;
        while(l < r) {
            long long mid = l + (r - l) / 2;
            if(valid(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};