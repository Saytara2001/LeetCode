class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0;
        for (auto c : moves) {
            if (c == 'L') {
                ++L;
                --R;
            } else if (c == 'R') {
                ++R;
                --L;
            } else {
                ++L, ++R;
            }
        }
        return max(L, R);
    }
};