class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(auto c: s) {
            if(iswalnum(c)) {
                t += tolower(c); //O(1)
            }
        }
        s = t;
        reverse(begin(s), end(s));
        return s == t;
    }
};