class Solution {
public:
    bool winnerOfGame(string s) {
        int a = 0, b = 0;
        int n = size(s);
        for(int i = 0; i < n; i++) {
            int cur = i;
            while(cur < n and s[cur] == s[i]) {
                cur++;
            }
            s[i] == 'A' ? a += max(0, cur - i - 2) : b += max(0, cur - i - 2); //max consequence
            i = cur - 1;
        }
        return a > b;
    }
};