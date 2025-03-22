class Solution {
public:
    struct DSU {
        vector<int> parent, sz, edges;

        DSU(int n) {
            parent.resize(n);
            edges.resize(n);
            sz.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                sz[i] = 1;
                edges[i] = 0;
            }
        }

        int FindParent(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = FindParent(parent[i]);
        }

        bool IsSameSet(int x, int y) {
            x = FindParent(x);
            y = FindParent(y);
            return (x == y);
        }

        bool Connect(int x, int y) {
            x = FindParent(x);
            y = FindParent(y);
            edges[x]++;
            if (x == y)
                return false;
            if (sz[x] < sz[y])
                swap(x, y);
            parent[y] = x;
            sz[x] += sz[y];
            edges[x] += edges[y];
            return true;
        }

        int Getsize(int x) {
            x = FindParent(x);
            return sz[x];
        }
    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int cccs = 0;
        DSU dsu(n);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            dsu.Connect(u, v);
        }
        vector<bool> vis(n);
        for(int i = 0; i < n; i++) {
            int p = dsu.FindParent(i);
            int sz = dsu.Getsize(i);
            if(!vis[p] and sz * (sz - 1) / 2 == dsu.edges[p]) {
                vis[p] = true;
                ++cccs;
            }
        }

        return cccs;
    }
};