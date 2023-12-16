class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26] = {0};
        for(auto it: s) {
            freq[it - 'a']++;
        }
        for(auto it : t) {
            if(--freq[it - 'a'] < 0)
                return false;
        }
        return size(s) == size(t);
    }
};