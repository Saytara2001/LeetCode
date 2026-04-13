class Solution {
public:
    int longestPath(vector<int> &parent, string s) {
        int n = s.size();
        vector<vector<int> > adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        int maxPath = 0;
        vector<int> dis(n, 0);
        function<void(int, int)> dfs = [&](int node, int par) {
            dis[node] = 1;
            for (auto child: adj[node]) {
                if (child == par) continue;
                dfs(child, node);
                if (s[node] != s[child]) {
                    dis[node] = max(dis[node], dis[child] + 1);
                }
            }
            int max1 = 0, max2 = 0;
            for (auto child: adj[node]) {
                int cur = dis[child];
                if(s[child] == s[node]) continue;
                if(cur > max1) {
                    max2 = max1;
                    max1 = cur;
                } else if(cur > max2) {
                    max2 = cur;
                }
            }
            maxPath = max(maxPath, max1 + max2 + 1);
        };
        dfs(0, -1);
        return maxPath;
    }
};