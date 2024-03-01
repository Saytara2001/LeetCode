class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = -1;
        int n = size(s);
        for(auto c: s) {
            ones += (c == '1');
        }
        for(int i = 0; i < n - 1; i++) {
            ones > 0 ? s[i] = '1', ones-- : s[i] = '0';
        }
        s.back() = '1';
        return s;
    }
};