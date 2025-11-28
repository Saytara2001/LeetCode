class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<vector<int>> adj(n);
        
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int comp = 0;
        vector<long long> sums(n);
        for(int i = 0; i < n; i++)
            sums[i] = values[i];
        
        function<void(int, int)> dfs = [&](int node, int par) {
            
            for(auto child: adj[node]) {
                if(child != par) {
                    dfs(child, node);
                    sums[node] += sums[child];
                }
            }
            comp += (sums[node] % k == 0);
        };   
        
        dfs(0, -1);
        
        return comp;
    }
};