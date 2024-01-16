class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' or c == 'e' or c == 'i' or c == 'u' or c == 'o';
    }
    string reverseVowels(string s) {
        int n = size(s);
        int l = 0, r = n - 1;
        while(l < r) {
            if(isVowel(s[l])) {
                while(!isVowel(s[r])) {
                    r--;
                }
                swap(s[l], s[r]);
                r--;
            }
            l++;
        }
        return s;
    }
};