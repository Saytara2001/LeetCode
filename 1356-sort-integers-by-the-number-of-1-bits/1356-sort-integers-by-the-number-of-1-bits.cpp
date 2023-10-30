#define popCount __builtin_popcount
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr), end(arr), [&](auto &a, auto &b){
            if(popCount(a) == popCount(b))
                return a < b;
            return popCount(a) < popCount(b);
        });
        return arr;
    }
};