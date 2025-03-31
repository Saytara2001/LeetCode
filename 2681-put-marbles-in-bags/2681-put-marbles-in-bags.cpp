class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {

        int n = size(weights);
        vector<int> score; // partitions of every two consequtive bags

        for(int i = 1; i < n; i++) {
            score.push_back(weights[i] + weights[i - 1]);
        }

        sort(begin(score), end(score));
        long long maxScore = weights[0] + weights[n - 1];
        long long minScore = maxScore;

        int sz = size(score);
        for(int i = 0; i < k - 1; i++) {
            minScore += score[i];
            maxScore += score[sz - i - 1];
        }

        return maxScore - minScore;
    }
};