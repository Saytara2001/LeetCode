class Solution {
public:
    vector<double> calcEquation(vector<vector<string> > &equations, vector<double> &values,
                                vector<vector<string> > &queries) {
        map<string, vector<pair<string, double> > > adj; // a -> {{b, 1}, {c, 5.5}}
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            adj[equations[i][0]].emplace_back(equations[i][1], values[i]);
            adj[equations[i][1]].emplace_back(equations[i][0], 1.0 / values[i]);
        }
        double result = -1.0;
        map<string, bool> vis;
        function<void(string, string &, double)> dfs = [&](string src, string &dis, double cur) {
            vis[src] = true;
            if (src == dis) {
                result = cur;
                return;
            }
            for (const auto &[child, cost]: adj[src]) {
                if (!vis[child]) {
                    dfs(child, dis, cur * cost);
                }
            }
        };
        vector<double> ans;
        for (auto query: queries) {
            result = -1.0;
            vis.clear();
            if (adj.count(query[0])) {
                dfs(query[0], query[1], 1.0);
            }
            ans.push_back(result);
        }
        return ans;
    }
};