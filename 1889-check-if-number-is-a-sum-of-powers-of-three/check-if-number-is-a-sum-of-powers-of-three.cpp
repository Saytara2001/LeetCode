class Solution {
public:
    bool checkPowersOfThree(int n) {

        vector<int> pow;

        int cur = 1;
        while(cur <= n) {
            pow.push_back(cur);
            cur *= 3;
        }

        for(int i = size(pow) - 1; i >= 0 and n > 0; i-- ) {
            if(n - pow[i] >= 0) {
                n -= pow[i];
            }
        }

        return n == 0;
    }
};