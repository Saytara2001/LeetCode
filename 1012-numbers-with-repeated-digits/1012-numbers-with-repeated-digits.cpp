class Solution {
public:
    string s;
    int dp[11][1<<10][2][2];

    int rec(int i, int msk, bool tight, bool num) {
        if (i == size(s)) return 1;
        
        int &ret = dp[i][msk][tight][num];
        if (~ret)
            return ret;

        ret = 0;
        int end = tight ? s[i] - '0' : 9;
        for (int j = 0; j <= end; j++) {
            if(msk & (1 << j)) continue; //visited before
            ret += rec(i + 1, j == 0 and !num ? msk : msk | (1 << j), tight and (j == end), num | (!!j));
        }

        return ret;

    }

    int numDupDigitsAtMostN(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof dp);
        //get all number which it's digits occur at most 1
        return (n + 1) - rec(0, 0, 1, 0); 
    }
};