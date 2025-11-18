class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int ones = 0, zeros = 0;
        int n = bits.size();
        for (int i = 0; i < n - 1; i++) {
            if (bits[i] == 0) {
                continue;
            } else if (i != n - 2) {
                ++i;
            } else {
                return false;
            }
        }
        return true;
    }
};