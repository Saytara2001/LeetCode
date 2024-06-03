class Solution {
public:
    int appendCharacters(string s, string t) {
        int p1 = 0, p2 = 0;
        int n = size(s), m = size(t);
        while(p1 < n and p2 < m) {
            if(s[p1] == t[p2]) {
                ++p2;
            }
            ++p1;
        }
        return m - p2;
    }
};