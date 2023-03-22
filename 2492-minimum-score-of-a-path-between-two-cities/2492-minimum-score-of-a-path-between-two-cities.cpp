struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
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

    void Connect(int x, int y) {
        x = FindParent(x);
        y = FindParent(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
    }

    int Getsize(int x) {
        x = FindParent(x);
        return sz[x];
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n+1);
        for(auto vv:roads) {
            dsu.Connect(vv[0], vv[1]);
        }
        int p = dsu.FindParent(1);
        int mn = 1e8;
        for(auto vv:roads) {
            if(p == dsu.FindParent(vv[0]))
                mn = min(mn, vv[2]);
        }
        return mn;
    }
};