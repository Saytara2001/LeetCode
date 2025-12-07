class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // prefix sum of plates
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (s[i] == '*');
        }

        // nearest candle to the left
        vector<int> leftCandle(n);
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|')
                last = i;
            leftCandle[i] = last;
        }

        // nearest candle to the right
        vector<int> rightCandle(n);
        last = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|')
                last = i;
            rightCandle[i] = last;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int L = q[0], R = q[1];

            int start = rightCandle[L]; // first candle inside [L, R]
            int end = leftCandle[R];    // last candle inside [L, R]

            if (start == -1 || end == -1 || start >= end)
                ans.push_back(0);
            else
                ans.push_back(prefix[end] - prefix[start]);
        }

        return ans;
    }
};