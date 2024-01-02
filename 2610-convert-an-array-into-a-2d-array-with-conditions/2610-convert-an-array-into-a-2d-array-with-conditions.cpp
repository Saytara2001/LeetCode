class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        while(nums.size()) {
            vector<int> vis(201), rem, cur;
            while(nums.size()) {
                if(!vis[nums.back()]) {
                    vis[nums.back()] = 1;
                    cur.push_back(nums.back());
                }else {
                    rem.push_back(nums.back());
                }
                nums.pop_back();
            }
            res.push_back(cur);
            nums = rem;
        }
        return res;
    }
};