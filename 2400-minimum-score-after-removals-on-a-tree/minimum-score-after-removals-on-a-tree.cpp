class Solution {
public:
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges) {
        int n = size(nums);
        vector<vector<int>> adj(n);
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int all = 0, final = 2e9;
        for (auto num: nums)
            all ^= num;
        function<int(int, int, int, int)> dfs2 = [&](int node, int par, int comp1, int anc) {
            int subXor = nums[node];
            for (auto child: adj[node]) {
                if (child == par) continue;
                subXor ^= dfs2(child, node, comp1, anc);
            }

            if (par == anc)
                return subXor;
            // update the answer
            int maxXor = max({comp1, subXor, all ^ comp1 ^ subXor});
            int minXor = min({comp1, subXor, all ^ comp1 ^ subXor});
            final = min(final, maxXor - minXor);

            return subXor;
        };
        function<int(int, int)> dfs1 = [&](int node, int par) {
            int subXor = nums[node];
            for (auto child: adj[node]) {
                if (child == par) continue;
                subXor ^= dfs1(child, node);
            }
            for (auto child: adj[node]) {
                if (child == par) {
                    dfs2(par, node, subXor, node);
                }
            }
            return subXor;
        };
        dfs1(0, -1);
        return final;
    }
};
