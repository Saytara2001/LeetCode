class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        auto anagram = [&](auto& s, auto& t) {
            if(t.size() != s.size()) return false;
            vector<int> freq(26);
            for(auto c: s) ++freq[c - 'a'];
            for(auto c: t) if(--freq[c - 'a'] < 0) return false;
            return true;
        };
        for(auto word: words) {
            if(res.empty() or !anagram(res.back(), word)) {
                res.push_back(word);
            }
        }
        return res;
    }
};