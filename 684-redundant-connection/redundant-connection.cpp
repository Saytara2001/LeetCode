class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = size(edges);
        vector<vector<int>> adj(n + 1);
        map<pair<int, int>, int> mp;
        for(int i = 0; i < n; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            mp[{edges[i][0], edges[i][1]}] = i + 1;
        }

        vector<int> inStack(n + 1), low(n  + 1), dfn(n + 1);
        stack<int> stk;
        int timer = 1;
        vector<int> cycle;
        function<void(int, int)> tarjan = [&] (int node, int par) {

            low[node] = dfn[node] = timer++;
            inStack[node] = true;
            stk.push(node);

            for (auto child: adj[node]) {
                if (!dfn[child]) {
                    tarjan(child, node);
                    // minimize ancestors of my child
                    low[node] = min(low[node], low[child]);
                } else if (child != par) { // visited + inStack = ancestor in cycle
                    low[node] = min(low[node], dfn[child]);
                }
            }
            // Get Comps
            if (low[node] == dfn[node]) {
                vector<int> new_comp;
                int x = -1;
                while (x != node) {
                    x = stk.top();
                    stk.pop();
                    inStack[x] = false;
                    new_comp.push_back(x);
                }
                if(new_comp.size() > 1) cycle = new_comp;
            }
        };

        tarjan(1, 0);

        int lst = -1;
        vector<int> ans(2);
        int sz = size(cycle);
        for(int i = 0; i < sz; i++) {
            int a = cycle[i], b = cycle[(i + 1) % sz];
            if(mp.count({a, b}) and mp[{a, b}] > lst) {
                lst = mp[{a, b}];
                ans[0] = a;
                ans[1] = b;
            }
            swap(a, b);
            if(mp.count({a, b}) and mp[{a, b}] > lst) {
                lst = mp[{a, b}];
                ans[0] = a;
                ans[1] = b;
            }
        }
        return ans;
    }
};