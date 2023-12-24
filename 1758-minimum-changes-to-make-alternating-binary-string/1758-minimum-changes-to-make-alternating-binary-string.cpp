class Solution {
public:
    int minOperations(string s) {
        int ans = 1e5, cnt = 0;
        char c = '1';
        for(auto it: s) {
            cnt += (c != it);
            c = '1' - c + '0';
        }
        ans = min(ans, cnt);
        c = '0'; cnt = 0;
        for(auto it: s) {
            cnt += (c != it);
            c = '1' - c + '0';
        }
        ans = min(ans, cnt);
        return ans;
    }
};