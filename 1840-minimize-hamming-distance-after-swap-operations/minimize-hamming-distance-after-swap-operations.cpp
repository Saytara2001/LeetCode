class Solution {
public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int> > &allowedSwaps) {
        int n = source.size();
        vector<vector<int> > adj(n);
        for (int i = 0; i < allowedSwaps.size(); i++) {
            int u = allowedSwaps[i][0];
            int v = allowedSwaps[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> used(n);
        vector<int> indices;
        function<void(int, int)> dfs = [&](int node, int par) {
            used[node] = true;
            indices.push_back(node);
            for (auto child: adj[node]) {
                if (par == child or used[child]) continue;
                dfs(child, node);
            }
        };
        int diff = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                indices.clear();
                dfs(i, -1);
                map<int, int> freq;
                for (auto j: indices) {
                    ++freq[source[j]];
                    --freq[target[j]];
                }
                for (auto [a, f]: freq) {
                    diff += f > 0 ? f : 0;
                }
            }
        }
        return diff;
    }
};