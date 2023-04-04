class Solution {
public:
    int partitionString(string s) {
        bool freq[26] = {0};
        int l = 0, r = 0, n = size(s);
        int sub = 0;
        while(l <= r and r < n) {
            sub++;
            while(r < n and !freq[s[r]-'a']) {
                freq[s[r++]-'a'] = 1;
            }
            while(l < r) {
                freq[s[l++]-'a'] = 0;
            }
        }
        return sub;
    }
};