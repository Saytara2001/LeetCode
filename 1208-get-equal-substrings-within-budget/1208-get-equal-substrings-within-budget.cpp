class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0, r = 0;
        int n = size(s);
        int curCost = 0, mx = 0;
        while(r < n) {
            curCost += abs(s[r] - t[r]);
            r++;
            while(curCost > maxCost) {
                curCost -= abs(s[l] - t[l]);
                l++;
            }
            mx = max(mx, r - l);
        }
        return mx;
    }
};