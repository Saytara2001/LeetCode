class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        multiset<int> ms;
        int n = size(values);
        for(int i = 0; i < n ; i++) {
            ms.insert(values[i] - i);
        }
        int maxScore = 0;
        for(int i = 0; i < n - 1; i++) {
            ms.erase(ms.find(values[i] - i));
            maxScore = max(maxScore, values[i] + i + *ms.rbegin());
        }
        return maxScore;
    }
};