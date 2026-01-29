class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dis(
            26, vector<int>(26, INT_MAX)); // if wrong change to Long long
        vector<vector<pair<int, int>>> adj(26);
        int m = original.size();
        for (int i = 0; i < m; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u].emplace_back(v, cost[i]);
        }

        auto bfs = [&](int st) {
            queue<pair<int, int>> q;
            q.push({st, 0});
            dis[st][st] = 0;
            while (q.size()) {
                auto [node, cur] = q.front();
                q.pop();
                for (auto [child, edgeCost] : adj[node]) {
                    if (dis[st][child] > cur + edgeCost) {
                        dis[st][child] = cur + edgeCost;
                        q.push({child, dis[st][child]});
                    }
                }
            }
        };
        for (int i = 0; i < 26; i++) {
            bfs(i); // relax every char
        }
        long long total = 0;
        for (int i = 0; i < source.size(); i++) {
            int a = source[i] - 'a';
            int b = target[i] - 'a';
            if (a == b)
                continue;
            if (dis[a][b] == INT_MAX)
                return -1;
            total += dis[a][b];
        }
        return total;
    }
};