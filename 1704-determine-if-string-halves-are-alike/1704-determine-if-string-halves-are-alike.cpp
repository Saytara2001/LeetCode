class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' or c == 'i' or c == 'u' or c == 'o' or c == 'e');
    }
    bool halvesAreAlike(string s) {
        int first = 0, second = 0;
        int n = size(s);
        for(int i = 0; i < n; i++) {
            if(i < n / 2) {
                first += isVowel(s[i]);
            }else {
                second += isVowel(s[i]);
            }
        }
        return (first == second);
    }
};