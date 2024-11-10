class Solution {
public:
    template<class T>
    struct SparseTable {
        vector<vector<T>> table;
        vector<int> lg;
        int n, mxLog;

        SparseTable(int sz) {
            n = sz;
            mxLog = __lg(n) + 1;
            table.resize(n + 1);
            lg.resize(n + 1);
            for (int i = 0; i <= n; ++i) {
                lg[i] = __lg(i);
                table[i].resize(mxLog);
            }
        }

        void build(vector<int> &v) {
            for (int i = 0; i < n; ++i)
                table[i][0] = v[i];

            for (int j = 1; j < mxLog; ++j)
                for (int i = 0; i + (1 << j) - 1 < n; ++i)
                    table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }

        T merge(T &l, T &r) {
            return (l | r);
        }

        T query(int l, int r) {
            int j = lg[r - l + 1];
            T left = table[l][j];
            T right = table[r - (1 << j) + 1][j];
            return merge(left, right);
        }
    };
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = size(nums);
        SparseTable<long long> sp(n);
        sp.build(nums);
        int shortest = n + 1;
        for (int i = 0; i < n; ++i) {
            int l = i, r = n;
            while (l < r) {
                int mid = l + (r - l) / 2;
                long long calc = sp.query(i, mid);
                if (calc >= k) {
                    shortest = min(shortest, mid - i + 1);
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
        }
        return (shortest == n + 1 ? -1 : shortest);
    }
};