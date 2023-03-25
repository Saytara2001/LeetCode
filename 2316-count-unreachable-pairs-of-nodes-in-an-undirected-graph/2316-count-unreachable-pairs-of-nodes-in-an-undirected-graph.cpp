class Solution {
public:
    int nodes = 0;
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = 1;
        nodes++;
        for(auto child:adj[node]) {
            if(!vis[child]) {
                dfs(child, adj, vis);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, 0);
        vector<vector<int>> adj(n);
        for(auto vv:edges) {
            adj[vv[0]].push_back(vv[1]);
            adj[vv[1]].push_back(vv[0]);
        }
        vector<int> v;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            nodes = 0;
            if(!vis[i]) {
                dfs(i, adj, vis);
                v.push_back(nodes);
                sum += nodes;
            }
        }
        long long ans = 0;
        for(int i = 0; i < v.size(); i++) {
            sum -= v[i];
            ans += 1LL * sum  * v[i];
        }
        return ans;
    }
};