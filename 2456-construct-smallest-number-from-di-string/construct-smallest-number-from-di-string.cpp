class Solution {
public:
    
    bool rec(int i, int lst, int& gen, long msk, string& pat) {
        if(i == size(pat) + 1) {
            return true;
        }

        for(int x = 1; x <= 9; x++) {
            if(msk & (1 << (x - 1))) continue;
            if(i > 0 and pat[i - 1] == 'I' and x < lst) continue;
            if(i > 0 and pat[i - 1] == 'D' and x > lst) continue;
            gen = gen * 10 + x;
            if(rec(i + 1, x, gen, msk | (1 << (x - 1)), pat))
                return true;
            gen /= 10;
        }

        return false;
    }
    string smallestNumber(string pattern) {
        int gen = 0;
        int res = rec(0, 1, gen, 0, pattern);
        string ans = to_string(gen);
        return ans;
    }
};