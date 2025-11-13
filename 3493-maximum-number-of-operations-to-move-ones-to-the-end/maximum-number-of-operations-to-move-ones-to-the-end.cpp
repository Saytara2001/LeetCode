class Solution {
public:
    int maxOperations(string s) {
        int ones = 0, ans = 0;
        char prev = 'x';
        for(auto c: s) {
            ones += c == '1';
            if(c == '0' and prev != '0') ans += ones;
            prev = c;
        }
        return ans;
    }
};