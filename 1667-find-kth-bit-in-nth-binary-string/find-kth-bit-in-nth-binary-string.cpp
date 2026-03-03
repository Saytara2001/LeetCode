class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while(s.size() < k) {
            s += '1';
            for(int i = s.size() - 2; i >= 0; i--) {
                s += char((s[i] - '0') ^ 1 + '0');
            }
        }
        return s[k - 1];
    }
};