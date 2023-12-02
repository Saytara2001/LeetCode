class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);
        for(auto it: chars) {
            freq[it - 'a']++;
        }
        int ans = 0;
        for(auto it: words) {
            bool ok = 1;
            for(auto ch: it) {
                if(--freq[ch - 'a'] < 0) {
                    ok = 0;
                }
            }
            if(ok) {
                ans += size(it);
            }
            for(auto ch: it) {
                ++freq[ch - 'a'];
            }
        }
        return ans;
    }
};