class Solution {
public:
    void rec(int lst, int k, int sum, vector<int> cur, vector<vector<int>> &res) {
        
        if(sum < 0 or cur.size() > k) return;
        if(sum == 0 and size(cur) == k) {
            res.push_back(cur);
            return;
        }
        
        for(int i = lst + 1; i <= 9; i++) {
            cur.push_back(i);
            rec(i, k, sum - i, cur, res);
            cur.pop_back();
        }
        
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        rec(0, k, n, {}, res);
        return res;
    }
};