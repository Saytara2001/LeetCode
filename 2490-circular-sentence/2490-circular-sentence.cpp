class Solution {
public:
    bool isCircularSentence(string s) {
        char lstChar;
        int n = size(s);
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                if(s[(i + 1) % n] != lstChar)
                    return false;
            } else {
                lstChar = s[i];
            }
        }
        return s[0] == lstChar;
    }
};