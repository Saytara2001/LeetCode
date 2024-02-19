class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool freq[300] = {0};
        int l = 0 , r = 0, n = size(s);
        int mx = 0;
        while(l <= r and r < n) {
            while(r < n and !freq[s[r]]) {
                freq[s[r++]] = true;
            }
            mx = max(mx, r - l);
            freq[s[l++]] = false;
        }
        return mx;
    }
};