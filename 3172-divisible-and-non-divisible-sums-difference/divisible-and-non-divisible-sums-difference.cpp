class Solution {
public:
    int differenceOfSums(int n, int m) {
        int all = n * (n + 1) / 2;
        int limit = n / m;
        all -= 2 * m * (limit * (limit + 1) / 2);       
        return all;                   
    }
};