class Solution {
public:
    int minimumLength(string s) {
        int n = size(s);
        int l = 0, r = n - 1;
        while(l < r) {
            char c = s[l];
            if(s[l] == s[r]) {
                while(l <= r and c == s[l]) {
                    l++;
                }
                while(l <= r and c == s[r]) {
                    r--;
                }
            }else {
                break;
            }
        }
        return r - l + 1;
    }
};