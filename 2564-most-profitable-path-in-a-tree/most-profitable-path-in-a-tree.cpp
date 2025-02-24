class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = size(edges);
        vector<vector<int>> adj(n + 1);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        function<bool(int, int, vector<int>&)> dfs = [&](int node, int par, vector<int>& path) {
            path.push_back(node);
            if(node == bob) return true;
            for(auto child: adj[node]) {
                if(child == par) continue;
                if(dfs(child, node, path))
                    return true;
            }
            path.pop_back();
            return false;
        };

        function<int(int, int, int)> maxProfit = [&](int node, int par, int profit) {
            
            int mx = INT_MIN;
            if(adj[node].size() == 1 and node != 0) 
                return profit;

            for(auto child: adj[node]) {
                if(child == par) continue;
                int res = maxProfit(child, node, profit + amount[child]);
                mx = max(mx, res);
            }

            return mx;
        };

        vector<int> path;
        dfs(0, -1, path);

        int sz = path.size();
        int profit = 0; 
        if(sz & 1) {
            amount[path[sz / 2]] /= 2;
        }
        for(int i = (sz + 1) / 2; i < sz; i++) {
            amount[path[i]] = 0;
        }
        
        return maxProfit(0, -1, 0) + amount[0];

    }
};