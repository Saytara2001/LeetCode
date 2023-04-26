class Solution {
public:
    int addDigits(int num) {
        while(num > 9) {
            int x = num, sum = 0;
            while(x) {
                sum += x % 10;
                x /= 10;
            }
            num = sum;
        }
        return num;
    }
};