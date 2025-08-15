struct segtree {
    int size;
    vector<int> values;
    int NEUTRAL_ELEMENT = 0;

    int merge(int a, int b) {
        return max(a, b);
    }

    int single(int v) {
        return v;
    }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        values.resize(2 * size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            //bottom tree
            values[x] = single(v);
            return;
        }
        int m = (lx + rx) >> 1;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return NEUTRAL_ELEMENT; // don't intersect
        if (lx >= l && rx <= r) return values[x]; // inside completly
        // part intersect and part don't intersect
        // so need to go deeper
        int m = (lx + rx) >> 1;
        int s1 = query(l, r, 2 * x + 1, lx, m);
        int s2 = query(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int MAX = 1e7 + 1;
segtree sg;
bool FirstCase = true;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
        if (FirstCase) {
            sg.init(MAX);
            FirstCase = false;
        }
        int n = obstacles.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            int mx = max(sg.query(0, obstacles[i] + 1) + 1, 1);
            sg.set(obstacles[i], mx);
            res[i] = mx;
        }
        // clear
        for (int i = 0; i < n; i++) {
            sg.set(obstacles[i], 0);
        }
        return res;
    }
};