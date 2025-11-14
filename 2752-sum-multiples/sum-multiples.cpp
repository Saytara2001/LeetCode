class Solution {
public:
    int sumOfMultiples(int n) {
        auto SUM = [&](int x) {
            return x * (x + 1) / 2;
        };
        int sum = 7 * SUM(n / 7);
        sum += 5 * SUM(n / 5);
        sum += 3 * SUM(n / 3);
        int lcm1 = 3 * 5;
        int lcm2 = 3 * 7;
        int lcm3 = 5 * 7;
        int lcm4 = 3 * 5 * 7;
        sum -= lcm1 * SUM(n / lcm1);
        sum -= lcm2 * SUM(n / lcm2);
        sum -= lcm3 * SUM(n / lcm3);
        sum += lcm4 * SUM(n / lcm4);
        return sum;
    }
};