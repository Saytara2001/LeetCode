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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsu1(n+1);
        int comp1 = n;
        int edge = 0;
        vector<pair<int, int>> blue, red;
        for(auto vv:edges) {
            if(vv[0] == 3) {
                if(dsu1.Connect(vv[1], vv[2])) {
                    edge++;
                    comp1--;
                }
            }
            if(vv[0] == 1) {
                red.push_back({vv[1], vv[2]});
            }
            if(vv[0] == 2) {
                blue.push_back({vv[1], vv[2]});
            }
        }     
        
        DSU dsu2(n+1);
        int comp2 = comp1;
        dsu2 = dsu1;
        for(auto vv:red) {
            if(dsu1.Connect(vv.first, vv.second)) {
                edge++;
                comp1--;
            }
        }
        for(auto vv:blue) {
            if(dsu2.Connect(vv.first, vv.second)) {
                edge++;
                comp2--;
            }
        }
        
        if(comp1 != 1 or comp2 != 1)
            return -1;
        
        return (int)(edges.size() - edge);
    }
};