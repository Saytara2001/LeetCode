class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> v(26);
        for(int i = 0; i < size(s) ; i++) {
            v[s[i] - 'a'].push_back(i);
        }
        int uni = 0;
        for(int c = 0; c < 26 ; c++) {
            if(v[c].size() < 2)
                continue;
            int ft = v[c][0], lst = v[c].back();
            for(int j = 0; j < 26; j++) {
                auto it = upper_bound(begin(v[j]), end(v[j]), ft);
                if(it != end(v[j]) and *it < lst)
                    uni++;
            }
        }
        return uni;
    }
};