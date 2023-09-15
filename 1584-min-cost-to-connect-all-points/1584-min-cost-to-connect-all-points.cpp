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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        priority_queue<pair<int, pair<int, int>>> pq;
        for(int i = 0 ; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int dis = abs(points[i][0] - points[j][0]) + 
                            abs(points[i][1] - points[j][1]);
                pq.push({-dis, {i, j}});
            }
        }
        int cost = 0;
        while(pq.size()) {
            int dis = -pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(dsu.Connect(i, j)) {
                cost += dis;
            }
        }
        return cost;
    }
};