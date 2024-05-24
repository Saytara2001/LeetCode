class Solution {
public:
    int rec(int i, vector<string>& words, vector<int>& freq, vector<int>& score) {
        if(i == size(words))
            return 0;
        
        int leave = rec(i + 1, words, freq, score);
        
        bool can = true;
        int res = 0;
        for(auto it: words[i]) {
            res += score[it - 'a'];
            if(--freq[it - 'a'] < 0) {
                can = false;
            }
        }
        int take = 0;
        if(can) {
            take = max(take, rec(i + 1, words, freq, score) + res);
        }
        
        for(auto it: words[i]) {
            ++freq[it - 'a'];
        }
        
        return max(take, leave);
        
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        for(auto it: letters) {
            freq[it - 'a']++;
        }
        return rec(0, words, freq, score);
    }
};