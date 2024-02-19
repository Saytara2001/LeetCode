class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool freq[300] = {0};
        int l = 0 , r = 0, n = size(s);
        int mx = 0;
        while(l <= r and r < n) {
            if(!freq[s[r]]) {
                freq[s[r++]] = true;
            }else {
                 freq[s[l++]] = false;
            }
            mx = max(mx, r - l);
        }
        return mx;
    }
};