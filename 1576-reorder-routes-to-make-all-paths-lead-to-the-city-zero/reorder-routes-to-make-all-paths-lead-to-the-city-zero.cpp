class Solution {
public:
    int minReorder(int n, vector<vector<int> > &connections) {
        vector<vector<pair<int, int> > > adj(n);
        for (auto connection: connections) {
            adj[connection[0]].emplace_back(connection[1], 1);
            adj[connection[1]].emplace_back(connection[0], 0);
        }
        function<int(int, int)> dfs = [&](int node, int par) {
            int res = 0;
            for (auto [child,cost]: adj[node]) {
                if (child == par) continue;
                res += dfs(child, node) + cost;
            }
            return res;
        };
        return dfs(0, -1);
    }
};