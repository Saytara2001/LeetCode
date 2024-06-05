class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = size(words);
        vector<vector<int>> freq(n, vector<int> (26));
        for(int i = 0; i < n; i++) {
            for(auto it : words[i]) {
                freq[i][it - 'a']++;
            }
        }
        vector<string> res;
        for(int i = 0; i < 26; i++) {
            int mn = 100;
            for(int j = 0; j < n; j++) {
                mn = min(mn, freq[j][i]);
            }
            while(mn--) {
                res.push_back(string(1, i + 'a'));
            }
        }
        return res;
    }
};