class Solution {
public:
    int countUniquePrimeFactors(int n) {
        int uni = 0;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) ++uni;
            while (n % i == 0) {
                n /= i;
            }
        }
        if (n != 1) ++uni;
        return uni;
    }

    long long BinPow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    int maximumScore(vector<int>& v, int k) {
        int n = size(v), mod = 1e9 + 7;
        vector<int> score(n);
        for (int i = 0; i < n; ++i) {
            score[i] = countUniquePrimeFactors(v[i]);
        }
        vector<int> left(n, -1), right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            // make the score monotonicly decreasing
            // to get the nearest greater than or equal to score
            while (stk.size() and score[stk.top()] < score[i])
                stk.pop();

            if (stk.size())
                left[i] = stk.top();

            stk.push(i);
        }
        while (stk.size()) stk.pop();
        for (int i = n - 1; i >= 0; --i) {
            // make the score monotonicly decreasing
            // to get the nearest greater than to score
            while (stk.size() and score[stk.top()] <= score[i])
                stk.pop();

            if (stk.size())
                right[i] = stk.top();

            stk.push(i);
        }
        priority_queue<pair<int, long long>> pq;
        for (int i = 0; i < n; ++i) {
            long long seg = 1LL * (i - left[i]) * (right[i] - i);
            pq.push({v[i], seg});
        }
        long long res = 1;
        while (pq.size() and k > 0) {

            auto top = pq.top();
            pq.pop();

            long long mn = min(1LL * k, top.second);
            k -= mn;

            res *= BinPow(top.first, mn, mod);
            res %= mod;
        }
        return res;
    }
};