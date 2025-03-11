class Solution {
public:
    int numberOfSubstrings(string s) {

        vector<int> freq(3);
        int n = size(s), sub = 0, l = 0;

        auto valid = [&]() {
            return freq[0] and freq[1] and freq[2];
        };

        for(int r = 0; r < n; r++) {
            ++freq[s[r] - 'a'];
            while(valid() and l < r) {
                sub += n - r;
                --freq[s[l] - 'a'];
                ++l;
            }
        }
        return sub;
    }
};