class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int longest = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26);
            for (int j = i; j < n; j++) {
                ++freq[s[j] - 'a'];
                bool bad = false;
                // check
                int prev = -1;
                for (int c = 0; c < 26; c++) {
                    if (freq[c] > 0) {
                        if (prev == -1)
                            prev = freq[c];
                        else if (prev != freq[c]) {
                            bad = true;
                            break;
                        }
                    }
                }
                if (!bad)
                    longest = max(longest, j - i + 1);
            }
        }
        return longest;
    }
};