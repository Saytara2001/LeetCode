class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(begin(events), end(events));
        int n = events.size();
        vector<int> suff(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            suff[i] = max(suff[i + 1], events[i][2]);
        }
        int maxScore = 0;
        for (int i = 0; i < n; i++) {
            maxScore = max(maxScore, events[i][2]);
            vector<int> need{events[i][1], INT_MAX, INT_MAX};
            auto idx =
                upper_bound(begin(events), end(events), need) - begin(events);
            if (idx < n) {
                maxScore = max(maxScore, events[i][2] + suff[idx]);
            }
        }
        return maxScore;
    }
};