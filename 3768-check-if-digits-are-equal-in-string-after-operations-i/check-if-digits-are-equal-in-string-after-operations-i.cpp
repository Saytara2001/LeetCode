class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2) {
            string gen = "";
            for(int i = 1; i < s.size(); i++) {
                int d = (s[i - 1] - '0' + s[i] - '0') % 10;
                gen += char(d + '0');            
            }
            s = gen;
        }
        return s.front() == s.back();
    }
};