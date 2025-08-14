class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int unique = 0, maxFruits = 0, l = 0;
        vector<int> freq(n + 1);
        for(int r = 0; r < n; r++) {
            unique += (++freq[fruits[r]] == 1);
            while(l < r and unique > 2) {
                unique -= !(--freq[fruits[l]]);
                ++l;
            }
            maxFruits = max(maxFruits, r - l + 1);
        }
        return maxFruits;
    }
};