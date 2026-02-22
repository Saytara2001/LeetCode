class Solution {
public:
    int binaryGap(int n) {
        int longest = 0, zeros = 0;
        bool flag = false;
        while (n > 0) {
            if (n & 1) {
                if (flag) {
                    longest = max(longest, zeros + 1);
                }
                zeros = 0;
                flag = true;
            } else {
                ++zeros;
            }
            n >>= 1;
        }
        return longest;
    }
};