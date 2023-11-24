class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int l = 0, r = size(piles) - 1;
        sort(begin(piles), end(piles));
        int have = 0;
        while(l < r) {
            l++;
            r--;
            have += piles[r--];
        }
        return have;
    }
};