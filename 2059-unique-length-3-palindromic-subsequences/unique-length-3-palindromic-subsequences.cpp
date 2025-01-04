class Solution {
public:
    int countPalindromicSubsequence(string s) {

        vector<vector<int>> idx(26, vector<int>(2, -1));
        for(int i = 0; i < size(s); i++) {
            if(idx[s[i]  - 'a'][0] == -1) {
                idx[s[i] - 'a'][0] = i;
            }else {
                 idx[s[i] - 'a'][1] = i;
            }
        }

        int uniquePalindrome = 0;
        vector<vector<bool>> vis(26, vector<bool>(26));
        for(int i = 1; i < int(size(s)) - 1; i++) {
            
            for(char c = 'a'; c <= 'z'; c++) {
                if(vis[s[i] - 'a'][c - 'a']) continue;
                if(idx[c - 'a'][0] < i and idx[c - 'a'][1] > i) {
                    vis[s[i] - 'a'][c - 'a'] = true;
                    ++uniquePalindrome;
                }
            }
        }

        return uniquePalindrome;
    }
};