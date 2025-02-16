class Solution {
public:
    bool rec(int i, int n, vector<int>& res, vector<bool>& vis) {
        if(i == 2 * n - 1) {
            return true;
        }

        if(res[i] != 0) {
            return rec(i + 1, n, res, vis);
        }
            

        for(int x = n; x >= 1; x--) {

            if(vis[x]) continue;

            vis[x] = true;
            res[i] = x;

            if(x == 1) {
                if(rec(i + 1, n, res, vis))
                    return true;
            } else if(i + x < 2 * n - 1 and !res[i + x]) {

                res[i + x] = x;

                if(rec(i + 1, n, res, vis))
                    return true;

                res[i + x] = 0;
            } 

            vis[x] = false;
            res[i] = 0;

        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<bool> vis(n + 1);
        vector<int> res(2 * n - 1);

        rec(0, n, res, vis);
        
        return res;
    }
};