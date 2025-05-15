class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = size(words);
        vector<string> res{words.front()};
        int lst = groups.front();
        for(int i = 1; i < n; i++) {
            if(lst != groups[i]) {
                res.push_back(words[i]);
                lst ^= 1;
            }
        }
        return res;
    }
};