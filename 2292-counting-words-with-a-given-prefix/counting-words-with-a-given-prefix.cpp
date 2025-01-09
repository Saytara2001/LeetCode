class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = size(words), m = size(pref);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += (pref == words[i].substr(0, m));
        }
        return cnt;
    }
};