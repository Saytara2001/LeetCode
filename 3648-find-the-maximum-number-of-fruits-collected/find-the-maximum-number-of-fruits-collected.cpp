class Solution {
public:
    int dp[1000][1000];
    int n, m;

    int child2(int i, int j, vector<vector<int> > &fruits) {
        if (j >= i or i < 0 or j < 0 or i >= n or j >= n) // can't cross the main diagonal
            return 0;

        if (i == n - 1 and j == n - 1)
            return 0;


        int &ret = dp[i][j];
        if (~ret)
            return ret;

        if (j + 1 < n) {
            ret = max(ret, child2(i, j + 1, fruits) + fruits[i][j]);
        }
        if (i - 1 >= 0 and j + 1 < n) {
            ret = max(ret, child2(i - 1, j + 1, fruits) + fruits[i][j]);
        }
        if (i + 1 < n and j + 1 < n) {
            ret = max(ret, child2(i + 1, j + 1, fruits) + fruits[i][j]);
        }
        return ret;
    }

    int child3(int i, int j, vector<vector<int> > &fruits) {
        if (i >= j or i < 0 or j < 0 or i >= n or j >= n) // can't cross the main diagonal
            return 0;

        if (i == n - 1 and j == n - 1)
            return 0;


        int &ret = dp[i][j];
        if (~ret)
            return ret;

        if (i + 1 < n) {
            ret = max(ret, child3(i + 1, j, fruits) + fruits[i][j]);
        }
        if (i + 1 < n and j - 1 >= 0) {
            ret = max(ret, child3(i + 1, j - 1, fruits) + fruits[i][j]);
        }
        if (i + 1 < n and j + 1 < n) {
            ret = max(ret, child3(i + 1, j + 1, fruits) + fruits[i][j]);
        }
        return ret;
    }

    int maxCollectedFruits(vector<vector<int> > &fruits) {
        n = fruits.size();
        m = fruits[0].size();
        int res = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            res += fruits[i][i];
        }
        cout << res << endl;
        res += child2(n - 1, 0, fruits);
        cout << res << endl;
        res += child3(0, n - 1, fruits);
        cout << res << endl;
        return res;
    }
};