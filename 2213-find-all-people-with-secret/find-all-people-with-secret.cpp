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

    int Connect(int x, int y) {
        x = FindParent(x);
        y = FindParent(y);
        if (x == y)
            return 0;
        if (x > y) {
            swap(x, y);
        }
        parent[y] = x;
        sz[x] += sz[y];
        return 1;
    }

    int Getsize(int x) {
        x = FindParent(x);
        return sz[x];
    }

    void Reset(int x) {
        parent[x] = x;
        sz[x] = 1;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int> > &meetings, int firstPerson) {

        map<int, vector<pair<int, int>>> sameTimeMeetings;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            sameTimeMeetings[t].emplace_back(x, y);
        }

        DSU dsu = DSU(n);
        dsu.Connect(0, firstPerson);
        for (auto& [t, meetings] : sameTimeMeetings) {
            // Unite two persons taking part in a meeting
            for (auto& [x, y] : meetings) {
                dsu.Connect(x, y);
            }

            // If any one knows the secret, both will be connected to 0.
            // If no one knows the secret, then reset.
            for (auto& [x, y] : meetings) {
                if (!dsu.IsSameSet(x, 0)) {
                    // No need to check for y since x and y were united
                    dsu.Reset(x);
                    dsu.Reset(y);
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (dsu.FindParent(i) == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};