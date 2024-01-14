class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        vector<int> freq1(26, 0), freq2(26, 0);
        
        for(auto it: word1) {
            freq1[it - 'a']++;
        }
        for(auto it: word2) {
            freq2[it - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            int cnt = (freq1[i] == 0) + (freq2[i] == 0);
            if(cnt == 1)
                return false;
        }
        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));
        
        return freq1 == freq2;
    }
};