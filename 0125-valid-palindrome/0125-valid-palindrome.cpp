class Solution {
public:
    bool isAlphaNumric(char c) {
        return (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9');
    }
    bool isPalindrome(string s) {
        string t = "";
        for(auto c: s) {
            if(isAlphaNumric(c)) {
                t += tolower(c); //O(1)
            }
        }
        int l = 0, r = size(t) - 1;
        while(l < r) {
            if(t[l] != t[r])
                return false;
            l++, r--;
        }
        return true;
    }
};