class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26] = {0};
        for(auto it: s) {
            freq[it - 'a']++;
        }
        int cnt = 0;
        for(auto it: t) {
            freq[it - 'a'] ? freq[it - 'a']-- : ++cnt;
        }
        return cnt;
    }
};