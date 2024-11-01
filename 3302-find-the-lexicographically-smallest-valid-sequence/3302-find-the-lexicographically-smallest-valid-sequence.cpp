class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        
        int n = size(word1), m = size(word2);
        vector<int> nextMatch(n + 1, m);
        
        // preprocess for longest suffix
        for(int i = n - 1, j = m - 1; i >= 0; i--) {
            nextMatch[i] = nextMatch[i + 1];
            if(j >= 0 and word1[i] == word2[j]) {
                nextMatch[i] = j;
                --j;
            }
        }
        
        bool changed = 0;
        vector<int> res;
        for(int i = 0, j = 0; i < n and j < m; i++) {
            if(word1[i] == word2[j]) {
                res.push_back(i);
                ++j;
            } else if(!changed and nextMatch[i + 1] <= j + 1) {
                 changed = 1;
                 res.push_back(i);
                 ++j;
            }
        }
        
        if(res.size() != m)
            return {};
        
        return res;
    }
};