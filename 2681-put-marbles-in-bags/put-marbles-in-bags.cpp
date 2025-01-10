class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {

        vector<int> pairs;
        int n = size(weights);
        
        for(int i = 0; i < n - 1; i++) {
            pairs.push_back(weights[i] + weights[i + 1]);
        }

        sort(begin(pairs), end(pairs));
        long long maxScore = weights.front() + weights.back();
        long long minScore = weights.front() + weights.back();
        
        for(int i = 0; i < k - 1; i++) {
            minScore += pairs[i];
            maxScore += pairs[n - i - 2];
        }
        return maxScore - minScore;
    }
};