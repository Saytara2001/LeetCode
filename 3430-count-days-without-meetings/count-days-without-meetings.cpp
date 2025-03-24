class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = size(meetings);
        sort(begin(meetings), end(meetings));
        vector<array<int, 2>> res;
        for(int i = 0; i < n; i++) {
            if(res.size() and res.back()[1] >= meetings[i][0]) {
                int mn = min(res.back()[0], meetings[i][0]);
                int mx = max(res.back()[1], meetings[i][1]);
                res.pop_back();
                res.push_back({mn, mx});
            } else {
                res.push_back({meetings[i][0], meetings[i][1]});
            }
        }
        int cnt = res[0][0] - 1; // get first days before work
        for(int i = 1; i < size(res); i++) {
            cnt += res[i][0] - res[i - 1][1] - 1;
        }
        cnt += days - res.back()[1]; // get last days after work
        return cnt;
    }
};