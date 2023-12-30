class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(27, 0);
        for(auto words: words) {
            for(auto c: words) {
                freq[c - 'a']++;
            }
        }
        int n = size(words);
        for(auto it: freq) {
            if(it % n != 0)
                return false;
        }
        return true;
    }
};