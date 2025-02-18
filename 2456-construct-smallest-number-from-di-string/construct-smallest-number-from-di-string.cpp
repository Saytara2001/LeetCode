class Solution {
public:
    int best;
    bool rec(int i, int lst, int gen, long msk, string& pat) {
        if(i == size(pat) + 1) {
            best = min(gen, best);
            return true;
        }

        for(int x = 1; x <= 9; x++) {
            if(msk & (1 << (x - 1))) continue;
            if(i > 0 and pat[i - 1] == 'I' and x < lst) continue;
            if(i > 0 and pat[i - 1] == 'D' and x > lst) continue;
            rec(i + 1, x, gen * 10 + x, msk | (1 << (x - 1)), pat);
        }

        return false;
    }
    string smallestNumber(string pattern) {
        best = INT_MAX;
        int res = rec(0, 1, 0, 0, pattern);
        string ans = to_string(best);
        return ans;
    }
};