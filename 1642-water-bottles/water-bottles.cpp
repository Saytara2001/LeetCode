class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = numBottles;
        int rem = 0;
        while(numBottles >= numExchange) {
            rem = numBottles % numExchange;
            numBottles /= numExchange;
            cnt += numBottles;
            numBottles += rem;
        }
        return cnt;
    }
};