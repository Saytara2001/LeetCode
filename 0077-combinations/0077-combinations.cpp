class Solution {
public:
    int sz;
    vector<vector<int>> res;
    void rec(int i, int k, vector<int> v) {
        
        if(v.size() == k) {
            res.push_back(v);
            return;
        }
                
        for(int start = i; start <= sz; start++) {
            v.push_back(start);
            rec(start + 1, k, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        sz = n;
        rec(1, k, {});
        return res;
    }
};