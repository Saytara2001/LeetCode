class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<array<int, 3>>> adj(n);
        int idx = 0;
        for(auto edge: redEdges) {
            adj[edge[0]].push_back({edge[1], 1, idx++}); // 1 ==> red edge
        }
        for(auto edge: blueEdges) {
             adj[edge[0]].push_back({edge[1], 2, idx++}); // 2 ==> blue edge
        }

        // BFS
        queue<array<int, 3>> q;
        vector<bool> vis(idx, false);
        vector<int> cost(n, -1);

        q.push({0, 0, -1});
        cost[0] = 0;

        while(q.size()) {
            int node = q.front()[0];
            int dist = q.front()[1];
            int lstColor = q.front()[2];
            q.pop();
            for(auto [child, color, idxEdge]: adj[node]) {
                if(!vis[idxEdge] and color != lstColor) {
                    vis[idxEdge] = true;
                    q.push({child, dist + 1, color});
                    if(cost[child] == -1) {
                        cost[child] = dist + 1;
                    }
                }
            }

        }
        return cost;
    }
};