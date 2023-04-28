class Solution {
public:
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

        bool Connect(int x, int y) {
            x = FindParent(x);
            y = FindParent(y);
            if (x == y)
                return 0;
            if (sz[x] < sz[y])
                swap(x, y);
            parent[y] = x;
            sz[x] += sz[y];
            return 1;
        }

        int Getsize(int x) {
            x = FindParent(x);
            return sz[x];
        }
    };
    int numSimilarGroups(vector<string>& v) {
        int n = v.size(), comp = n;
        DSU dsu(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                set<char> set;
                for (int k = 0; k < v[i].size(); ++k) {
                    if (v[i][k] != v[j][k]) {
                        set.insert(v[i][k]);
                        set.insert(v[j][k]);
                    }
                    if(set.size() > 2)
                        break;
                }
                if (set.size() == 2 or set.size() == 0) {
                    if(dsu.Connect(i, j))
                        comp--;
                }
            }
        }
        return comp;
    }
};