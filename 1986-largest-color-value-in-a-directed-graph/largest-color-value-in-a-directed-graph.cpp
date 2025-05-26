class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>> &edges) {
        int n = size(colors);
        vector<int> in(n);
        vector<vector<int>> adj(n);
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            in[edge[1]]++;
        }
        queue<int> q;
        vector<vector<int>> cnt(n, vector<int>(26));
        for (int i = 0; i < n; ++i) {
            if (!in[i]) {
                cnt[i][colors[i] - 'a'] = 1; // set color for each node
                q.push(i);
            }
        }
        int LCV = 1; // largest color value
        while (q.size()) {
            int node = q.front();
            q.pop();
            for (auto child: adj[node]) {
                int curColor = colors[child] - 'a';
                for (int c = 0; c < 26; ++c) {
                    cnt[child][c] = max(cnt[child][c], cnt[node][c] + (c == curColor));
                    LCV = max(LCV, cnt[child][c]);
                }
                if (--in[child] == 0) {
                    q.push(child);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (in[i] > 0)
                return -1;
        }
        return LCV;
    }
};