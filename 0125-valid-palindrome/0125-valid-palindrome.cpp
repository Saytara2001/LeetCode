class Solution {
public:
    bool isPalindrome(string s) {
        int n = size(s);
        int l = 0, r = n - 1;
        while(l < r) {
            while(l < r and !iswalnum(s[l])) l++;
            while(l < r and !iswalnum(s[r])) r--;
            if(tolower(s[l]) != tolower(s[r])) return false; 
            l++, r--;
        }
        return true;
    }
};