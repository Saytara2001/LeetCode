class Solution {
public:
    int totalMoney(int n) {
        int ans = 0, first = 0;
        while(n > 0) {
            int mn = min(n, 7);
            ans += (mn + first) * (mn + first + 1) / 2 - first * (first + 1) / 2;
            first++;
            n -= mn;
        }
        return ans;
    }
};