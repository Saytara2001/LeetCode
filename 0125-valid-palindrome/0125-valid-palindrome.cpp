class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(auto c: s) {
            if(iswalnum(c)) {
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