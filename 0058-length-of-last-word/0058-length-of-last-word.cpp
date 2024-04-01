class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        while(s.size() and s.back() == ' ') s.pop_back();
        while(s.size() and s.back() != ' ') s.pop_back(), len++;
        return len;
    }
};