class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        //track two minimum value
        int mn1 = 100, mn2 = 100;
        for(auto it: prices) {
            if(mn1 > it) {
                mn2 = mn1;
                mn1 = it;
            }else {
                mn2 = min(mn2, it);
            }
        }
        if(mn1 + mn2 <= money)
            return money - mn1 - mn2;
        return money;
    }
};