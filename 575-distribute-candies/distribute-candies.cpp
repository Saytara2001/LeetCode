class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> unique;
        for(auto candy: candyType) {
            unique.insert(candy);
        }
        return min(n / 2, int(unique.size()));
    }
};