class Solution {
public:
    bool isPalindrome(string s) {
        string tmp = "";
        for(auto c: s) {
            if(iswalnum(c)) {
                tmp += tolower(c);
            }
        }
        int n = size(tmp);
        for(int i = 0; i < n / 2; i++) {
            if(tmp[i] != tmp[n - i - 1])
                return false;
        }
        return true;
    }
};