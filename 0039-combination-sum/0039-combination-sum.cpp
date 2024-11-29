class Solution {
public:
    void rec(int st, int sum, vector<int>& v, vector<int> cur, vector<vector<int>> &res) {
        
        if(sum == 0) {
            res.push_back(cur);
            return;
        }
        
        for(int i = st; i < size(v); i++) {
            if(sum >= v[i]) {
                cur.push_back(v[i]);
                rec(i, sum - v[i], v, cur, res);
                cur.pop_back();
            }
        }
        
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        rec(0, target, candidates, {}, res);
        return res;
    }
};