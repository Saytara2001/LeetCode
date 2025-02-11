class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {

        
        int n = size(roads) + 1;
        vector<vector<int>> adj(n);

        for(auto edge: roads) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        long long minCost = 0;
        vector<int> sub(n, 1);
        function<void(int, int)> dfs = [&](int node, int par) {
            for(auto child: adj[node]) {
                if(child == par) continue;
                dfs(child, node);
                sub[node] += sub[child];
            }
            if(node != 0)
                minCost += (sub[node] + seats - 1) / seats;
        };
        
        dfs(0, -1);

        return minCost;
    }
};