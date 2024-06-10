class Solution {
public:
    string s;
    int dp[11][10][2][3][3][3][3][3][3][3][3][3][3];

    int rec(int i, bool tight, bool num, int x0, int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9) {
        if (i == size(s)) {
            bool ok = false;
            ok |= (x0 > 1);
            ok |= (x1 > 1);
            ok |= (x2 > 1);
            ok |= (x3 > 1);
            ok |= (x4 > 1);
            ok |= (x5 > 1);
            ok |= (x6 > 1);
            ok |= (x7 > 1);
            ok |= (x8 > 1);
            ok |= (x9 > 1);
            return ok;
        }
        int &ret = dp[i][tight][num][x0][x1][x2][x3][x4][x5][x6][x7][x8][x9];
        if (~ret)
            return ret;

        ret = 0;
        int end = tight ? s[i] - '0' : 9;
        for (int j = 0; j <= end; j++) {
            if (j == 0) {
                ret += rec(i + 1, tight and (j == end), num, (num ? min(2, x0 + 1) : 0), x1, x2, x3, x4, x5, x6, x7, x8, x9);
            }
            if (j == 1) {
                ret += rec(i + 1, tight and (j == end), 1, x0, min(2, x1 + 1), x2, x3, x4, x5, x6, x7, x8, x9);
            }
            if (j == 2) {
                ret += rec(i + 1, tight and (j == end), 1, x0, x1, min(2, x2 + 1), x3, x4, x5, x6, x7, x8, x9);
            }
            if (j == 3) {
                ret += rec(i + 1, tight and (j == end), 1, x0, x1, x2, min(2, x3 + 1), x4, x5, x6, x7, x8, x9);
            }
            if (j == 4) {
                ret += rec(i + 1, tight and (j == end), 1, x0, x1, x2, x3, min(2, x4 + 1), x5, x6, x7, x8, x9);
            }
            if (j == 5) {
                ret += rec(i + 1, tight and (j == end), 1, x0, x1, x2, x3, x4, min(2, x5 + 1), x6, x7, x8, x9);
            }
            if (j == 6) {
                ret += rec(i + 1, tight and (j == end), 1, x0, x1, x2, x3, x4, x5, min(2, x6 + 1), x7, x8, x9);
            }
            if (j == 7) {
                ret += rec(i + 1, tight and (j == end), 1, x0, x1, x2, x3, x4, x5, x6, min(2, x7 + 1), x8, x9);
            }
            if (j == 8) {
                ret += rec(i + 1, tight and (j == end), 1, x0, x1, x2, x3, x4, x5, x6, x7, min(2, x8 + 1), x9);
            }
            if (j == 9) {
                ret += rec(i + 1, tight and (j == end), 1, x0, x1, x2, x3, x4, x5, x6, x7, x8, min(2, x9 + 1));
            }

        }

        return ret;

    }

    int numDupDigitsAtMostN(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof dp);
        return rec(0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
};