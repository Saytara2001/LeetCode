class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = size(colors);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int cur = i, sum = 0, mx = 0;
            while(cur < n and colors[cur] == colors[i]) {
                sum += neededTime[cur];
                mx = max(mx, neededTime[cur++]);
            }
            i = cur - 1;
            ans += sum - mx;
        }
        return ans;
    }
};