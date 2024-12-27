class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = size(values);
        int maxScore = 0, bestPrev = values[0];
        for(int i = 1; i < n; i++) {
            maxScore = max(maxScore, bestPrev + values[i] - i);
            bestPrev = max(bestPrev, values[i] + i);
        }
        return maxScore;
    }
};