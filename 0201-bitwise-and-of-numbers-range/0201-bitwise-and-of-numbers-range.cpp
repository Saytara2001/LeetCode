class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //get the common prefix
        int shift = 0;
        while(left != right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return (left << shift);
    }
};