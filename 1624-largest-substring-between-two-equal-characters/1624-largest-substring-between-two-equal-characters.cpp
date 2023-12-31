class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int LongestSubstring = -1;
        vector<int> start(26, -1), end(26, -1);
        for(int i = 0; i < size(s); i++) {
            if(start[s[i] - 'a'] == -1)
                start[s[i] - 'a'] = i;
            end[s[i] - 'a'] = i;
            LongestSubstring = max(LongestSubstring, end[s[i] - 'a'] - start[s[i] - 'a'] - 1);
        }
        return LongestSubstring;
    }
};