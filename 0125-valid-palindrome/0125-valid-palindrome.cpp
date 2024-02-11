class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(auto c: s) {
            if(iswalnum(c)) {
                t += tolower(c); //O(1)
            }
        }
        int n = size(t);
        for(int i = 0 ; i < n / 2; i++) {
            if(t[i] != t[n - i - 1])
                return false;
        }
        return true;
    }
};