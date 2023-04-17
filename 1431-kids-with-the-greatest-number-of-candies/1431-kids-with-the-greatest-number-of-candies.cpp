class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;
        for(auto vv:candies) {
            mx = max(mx, vv);
        }
        vector<bool> res;
        for(int i = 0; i < size(candies); i++) {
            res.push_back(candies[i] + extraCandies >= mx);
        }
        return res;
    }
};