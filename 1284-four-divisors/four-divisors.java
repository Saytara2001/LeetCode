class Solution {
    public int sumFourDivisors(int[] nums) {
        int ans = 0;
        for (int num : nums) {
            int div = 0, sum = 0;
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    int j = num / i;
                    div++;
                    sum += i;
                    if (j != i) {
                        div++;
                        sum += j;
                    }
                    if (div > 4)
                        break;
                }
            }
            if (div == 4)
                ans += sum;
        }
        return ans;
    }
}