class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> freq;
        for(auto point: points) {
            freq[point[1]]++;
        }
        const int mod = 1e9 + 7;
        auto Sum = [&](int n) -> long long{
            return 1LL * n * (n - 1) / 2;
        };
        long long sum = 0, cnt = 0;
        for(auto [x, f] : freq) {
            int comp = Sum(f);
            cnt += 1LL * sum * comp;
            sum += comp;
            cnt %= mod;
        }
        return cnt;
    }
};