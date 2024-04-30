class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int msk = 0;
        long long res = 0;
        map<int, int> pref;
        pref[0] = 1;
        for(auto c: word) {
            int bit = c - 'a';
            msk ^= (1 << bit);
            res += pref[msk]; //if msk equal to zeros count it
            for(int i = 0; i < 10; i++) {
                res += pref[msk ^ (1 << i)];
            }
            pref[msk]++;
        }
        return res;
    }
};