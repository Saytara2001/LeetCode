class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int maxLength = 0;
        unordered_map<string, int> freq;
        for(auto word: words) {
            string tmp = word;
            reverse(begin(tmp), end(tmp));
            if(freq[tmp] > 0) {
                maxLength += 2;
                --freq[tmp];
            } else {
                ++freq[word];
            }
        }
        for(auto& [a, b]: freq) {
            if(a[0] == a[1] and b > 0) {
                ++maxLength;
                break;
            }
        }
        return maxLength * 2;
    }
};