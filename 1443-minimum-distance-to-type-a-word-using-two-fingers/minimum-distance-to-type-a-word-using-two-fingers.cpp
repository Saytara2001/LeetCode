class Solution {
public:
    int dp[300][5][6][5][6];
    pair<int, int> getPos(char c) {
        int x = c - 'A';
        int row = x / 6;
        int col = x % 6;
        return {row, col};
    }
    int getDistance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int rec(int i, int x1, int y1, int x2, int y2, string& word) {
        if (i == size(word))
            return 0;

        int& ret = dp[i][x1][y1][x2][y2];
        if (~ret)
            return ret;

        ret = INT_MAX;

        auto [x, y] = getPos(word[i]);
        int dis1 = getDistance(x1, y1, x, y);
        int dis2 = getDistance(x2, y2, x, y);

        ret = min(ret, rec(i + 1, x, y, x2, y2, word) + dis1);
        ret = min(ret, rec(i + 1, x1, y1, x, y, word) + dis2);

        return ret;
    }
    int minimumDistance(string word) {
        memset(dp, -1, sizeof dp);
        // try start from all positions of each letter
        int ans = INT_MAX;
        for(char a = 'A'; a <= 'Z'; a++) {
            for(char b = 'A'; b <= 'Z'; b++) {
                auto [x1, y1] = getPos(a);
                auto [x2, y2] = getPos(b);
                ans = min(ans, rec(0, x1, y1, x2, y2, word));
            }
        }
        return ans;
        
    }
};