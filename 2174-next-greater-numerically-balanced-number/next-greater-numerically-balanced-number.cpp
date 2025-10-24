class Solution {
public:
    // 1 22 333
    int ans = 1e9;
    void rec(int x, int n, vector<int> &cur) {
        if (x == 8) {
            if (cur.size() > 7) return;
            // get all permutations
            vector<int> gen = cur;
            do {
                int num = 0;
                for (auto d: gen) {
                    num = num * 10 + d;
                }
                if (num > n) ans = min(ans, num);
            } while (next_permutation(begin(gen), end(gen)));
            return;
        }
        rec(x + 1, n, cur);
        if (cur.size() < 7) {
            for (int i = 1; i <= x; i++) {
                cur.push_back(x);
            }
            rec(x + 1, n, cur);
            for (int i = 1; i <= x; i++) {
                cur.pop_back();
            }
        }
    }

    int nextBeautifulNumber(int n) {
        vector<int> v;
        rec(1, n, v);
        return ans;
    }
};