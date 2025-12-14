class Solution {
public:
    int numberOfWays(string corridor) {
        int s = count(begin(corridor), end(corridor), 'S');
        if((s & 1) or !s)
            return 0;

        int ans = 1;
        const int mod = 1e9 + 7;
        int cntS = 0, prevCntS = 0, counter = 1;
        for (int i = 0; i < corridor.size() - 1; i++) {
            cntS += corridor[i] == 'S';
            if(cntS == prevCntS and cntS % 2 == 0 and cntS > 0) {
                ++counter;
                continue;
            } 
            ans = (1LL * ans * counter) % mod;
            counter = 1;
            prevCntS = cntS;
        }
        return ans;
    }
};