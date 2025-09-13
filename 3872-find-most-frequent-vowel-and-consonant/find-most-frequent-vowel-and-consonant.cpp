class Solution {
public:
    int maxFreqSum(string s) {
        auto isVowel = [&] (char c) {
            return c == 'a' or c == 'i' or c =='e' or c == 'o' or c == 'u';
        };
        int maxVowels = 0, maxConsonants = 0;
        vector<int> freq(26);
        for(auto c: s) {
            ++freq[c - 'a'];
            if(isVowel(c)) {
                if(maxVowels < freq[c - 'a']) {
                    maxVowels = freq[c - 'a'];
                }
            } else {
                if(maxConsonants < freq[c - 'a']) {
                    maxConsonants = freq[c - 'a'];
                }
            }
        }
        return maxVowels + maxConsonants;
    }
};