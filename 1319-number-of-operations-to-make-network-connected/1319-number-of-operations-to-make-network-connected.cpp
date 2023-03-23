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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int cables = 0, comp = n;
        for(auto vv:connections) {
            int a = dsu.FindParent(vv[0]); 
            int b = dsu.FindParent(vv[1]);

            if(!dsu.Connect(a, b))
                cables++;
            else
                comp--;
        }
        if(comp-1 <= cables)
            return comp-1;
        return -1;
    }
};