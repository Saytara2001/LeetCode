class Solution {
public:
    vector<int> computePrefix(string &pat) {
        int n = pat.size();
        vector<int> longestPrefix(n);
        for (int i = 1, k = 0; i < n; ++i) {
            while (k > 0 and pat[i] != pat[k])
                k = longestPrefix[k - 1];

            if (pat[i] == pat[k])
                longestPrefix[i] = ++k;
            else
                longestPrefix[i] = k;
        }
        return longestPrefix;
    }

    string Kmp(string &s, string &pat) {

        int n = s.size();
        int m = pat.size();
        vector<int> longestPrefix = computePrefix(pat);

        int i = 0, k = 0;
        while (i < n) {

            if (s[i] == pat[k]) {
                ++k, ++i;
            } else {
                if (k > 0)
                    k = longestPrefix[k - 1]; // fail to try match
                else
                    ++i; // we can't match 
            }

            // matched pattern
            if (k == m) {
                s = s.substr(0, i - m) + s.substr(i, n);
                i = max(i - 2 * m, 0); // match.push_back(i - m + 1);
                k = 0; // start to match pattern from first again
                n = size(s);
            }
        }
        return s;
    }
    string removeOccurrences(string s, string part) {
        return Kmp(s, part);
    }
};