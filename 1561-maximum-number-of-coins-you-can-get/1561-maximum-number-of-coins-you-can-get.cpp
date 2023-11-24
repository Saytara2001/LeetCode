class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int have = 0;
        sort(begin(piles), end(piles));
        for (int i = piles.size() / 3; i < piles.size(); i += 2) {
            have += piles[i];
        }
        return have;
    }
};