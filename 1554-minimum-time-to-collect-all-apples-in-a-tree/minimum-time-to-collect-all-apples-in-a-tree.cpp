class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        vector<vector<int>> adj(n);

        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int time = 0;
        vector<int> sub(n);
        function<void(int, int)> dfs = [&](int node, int par) {
            for(auto child: adj[node]) {
                if(child == par) continue;
                dfs(child, node);
                sub[node] |= (sub[child] | hasApple[child]);
                if(sub[child] or hasApple[child])  {
                    time += 2;
                }
            }
        };

        dfs(0, -1);

        return time;
    }
};