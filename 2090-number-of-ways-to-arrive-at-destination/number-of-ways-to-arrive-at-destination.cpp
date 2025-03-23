class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: roads) {
            adj[it[0]].emplace_back(it[1], it[2]);
            adj[it[1]].emplace_back(it[0], it[2]);
        }

        priority_queue<pair<long long, int>> pq;
        vector<long long> dis(n, 2e18), ways(n, 0);

        pq.push({0, 0}); // distance, node
        dis[0] = 0;
        ways[0] = 1;

        while(pq.size()) {
            auto cost = -pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            for(auto [child, time]: adj[node]) {
                long long nc = cost + time;
                if(dis[child] > nc) {
                    dis[child] = nc;
                    ways[child] = ways[node];
                    pq.push({-nc, child});
                } else if(dis[child] == nc) {
                    ways[child] += ways[node];
                    ways[child] %= mod;
                }
            }
        }


        return ways[n - 1];
    }
};