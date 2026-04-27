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
            return false;
        if (sz[x] < sz[y])
            swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
        return true;
    }

    int Getsize(int x) {
        x = FindParent(x);
        return sz[x];
    }
};

class Solution {
public:
    bool hasValidPath(vector<vector<int> > &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sz = n * m;
        DSU dsu(sz + 5);
        auto getIndex = [&](int i, int j) {
            return i * m + j;
        };
        auto street1 = [&](int i, int j) {
            if (j - 1 >= 0 and (grid[i][j - 1] == 1 or grid[i][j - 1] == 4 or grid[i][j - 1] == 6))
                dsu.Connect(getIndex(i, j), getIndex(i, j - 1));
            if (j + 1 < m and (grid[i][j + 1] == 1 or grid[i][j + 1] == 3 or grid[i][j + 1] == 5))
                dsu.Connect(getIndex(i, j), getIndex(i, j + 1));
        };
        auto street2 = [&](int i, int j) {
            if (i - 1 >= 0 and (grid[i - 1][j] == 2 or grid[i - 1][j] == 3 or grid[i - 1][j] == 4))
                dsu.Connect(getIndex(i, j), getIndex(i - 1, j));
            if (i + 1 < n and (grid[i + 1][j] == 2 or grid[i + 1][j] == 5 or grid[i + 1][j] == 6))
                dsu.Connect(getIndex(i, j), getIndex(i + 1, j));
        };
        auto street3 = [&](int i, int j) {
            if (j - 1 >= 0 and (grid[i][j - 1] == 1 or grid[i][j - 1] == 4))
                dsu.Connect(getIndex(i, j), getIndex(i, j - 1));
            if (i + 1 < n and (grid[i + 1][j] == 2 or grid[i + 1][j] == 5 or grid[i + 1][j] == 6))
                dsu.Connect(getIndex(i, j), getIndex(i + 1, j));
        };
        auto street4 = [&](int i, int j) {
            if (j + 1 < m and (grid[i][j + 1] == 1 or grid[i][j + 1] == 3 or grid[i][j + 1] == 5))
                dsu.Connect(getIndex(i, j), getIndex(i, j + 1));
            if (i + 1 < n and (grid[i + 1][j] == 2 or grid[i + 1][j] == 6))
                dsu.Connect(getIndex(i, j), getIndex(i + 1, j));
        };
        auto street5 = [&](int i, int j) {
            if (i - 1 >= 0 and (grid[i - 1][j] == 2 or grid[i - 1][j] == 3 or grid[i - 1][j] == 4))
                dsu.Connect(getIndex(i, j), getIndex(i - 1, j));
            if (j - 1 >= 0 and (grid[i][j - 1] == 1 or grid[i][j - 1] == 4 or grid[i][j - 1] == 6))
                dsu.Connect(getIndex(i, j), getIndex(i, j - 1));
        };
        auto street6 = [&](int i, int j) {
            if (i - 1 >= 0 and (grid[i - 1][j] == 2 or grid[i - 1][j] == 3 or grid[i - 1][j] == 4))
                dsu.Connect(getIndex(i, j), getIndex(i - 1, j));
            if (j + 1 < m and (grid[i][j + 1] == 1 or grid[i][j + 1] == 3 or grid[i][j + 1] == 5))
                dsu.Connect(getIndex(i, j), getIndex(i, j + 1));
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = grid[i][j];
                switch (x) {
                    case 1:
                        street1(i, j);
                        break;
                    case 2:
                        street2(i, j);
                        break;
                    case 3:
                        street3(i, j);
                        break;
                    case 4:
                        street4(i, j);
                        break;
                    case 5:
                        street5(i, j);
                        break;
                    case 6:
                        street6(i, j);
                        break;
                }
            }
        }
        return dsu.IsSameSet(getIndex(0, 0), getIndex(n - 1, m - 1));
    }
};