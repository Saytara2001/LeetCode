class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' or c == 'e' or c == 'i' or c == 'u' or c == 'o';
    }
    string reverseVowels(string s) {
        vector<char> vowels;
        for(auto it: s) {
            if(isVowel(it)) {
                vowels.push_back(it);
            }
        }
        for(auto &it: s) {
            if(isVowel(it)) {
                it = vowels.back();
                vowels.pop_back();
            }
        }
        return s;
    }
};