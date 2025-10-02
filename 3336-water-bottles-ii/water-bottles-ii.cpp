class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = 0, empty = 0;
        while(numBottles > 0 or (empty >= numExchange)) {
            res += numBottles;
            empty += numBottles;
            numBottles = 0;
            if(empty >= numExchange) {
                empty -= numExchange++;
                numBottles = 1;
            }
        }

        return res;
    }
};