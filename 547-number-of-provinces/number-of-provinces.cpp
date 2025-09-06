class Solution {
public:
    int findCircleNum(vector<vector<int> > &isConnected) {
        int n = isConnected.size();
        vector<vector<int> > adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n);
        function<void(int)> dfs = [&](int node) {
            vis[node] = true;
            for (auto child: adj[node]) {
                if (!vis[child]) {
                    dfs(child);
                }
            }
        };
        int province = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ++province;
                dfs(i);
            }
        }
        return province;
    }
};