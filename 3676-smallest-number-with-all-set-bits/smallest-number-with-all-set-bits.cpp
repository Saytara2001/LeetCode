class Solution {
public:
    int smallestNumber(int n) {
        bool flag = false;
        for(int msk = 20; msk >= 0; msk--) {
            flag |= (n & (1 << msk));
            if(flag) {
                n |= (1 << msk);
            }
        }
        return n;
    }
};