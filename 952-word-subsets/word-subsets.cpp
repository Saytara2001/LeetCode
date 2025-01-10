class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> res;
        vector<int> maxfreq(26);
        for(auto word: words2) {

            vector<int> freq(26);
            for(auto c: word) {
                freq[c - 'a']++;
            }

            for(int i = 0; i < 26; i++)
                maxfreq[i] = max(maxfreq[i], freq[i]);
        }

        
        for(auto word: words1) {
            vector<int> curFreq(26);
            for(auto c: word) {
                curFreq[c - 'a']++;
            }
            bool ok = true;
            for(int i = 0; i < 26; i++) {
                ok &= maxfreq[i] <= curFreq[i];
            }
            if(ok) res.push_back(word);
        }
        return res;
    }
};