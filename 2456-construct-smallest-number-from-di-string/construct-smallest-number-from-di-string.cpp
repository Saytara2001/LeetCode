class Solution {
public:
    
    int rec(int i, int lst, int gen, long msk, string& pat) {
        int best = INT_MAX;
        if(i == size(pat) + 1) {
            return gen;
        }

        for(int x = 1; x <= 9; x++) {
            if(msk & (1 << (x - 1))) continue;
            if(i > 0 and pat[i - 1] == 'I' and x < lst) continue;
            if(i > 0 and pat[i - 1] == 'D' and x > lst) continue;
            best = min(best, rec(i + 1, x, gen * 10 + x, msk | (1 << (x - 1)), pat));
        }

        return best;
    }
    string smallestNumber(string pattern) {
        int res = rec(0, 1, 0, 0, pattern);
        string ans = to_string(res);
        return ans;
    }
};