class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<vector<int>> adj(n);
        
        for(auto it: edges) {
            adj[it.front()].push_back(it.back());
            adj[it.back()].push_back(it.front());
        }
        
        int comp = 0;
        vector<long long> dp(n, 0);
        
        function<void(int, int)> dfs = [&](int node, int p) {
            dp[node] = 1LL * values[node]; 
            for (auto child: adj[node]) {
                if (child != p) {
                    dfs(child, node);
                    if(dp[child] % k == 0) {
                        comp++;
                    }else {
                        dp[node] += dp[child];
                    }
                }
            }
        };
        dfs(0, 0);
        return comp + 1;
    }
};