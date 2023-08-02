class Solution {
public:
    int n;
    map<int, bool> vis;
    vector<vector<int>> res; 
    void rec(vector<int> v, vector<int>& nums) {
        if(v.size() == n) {
            res.push_back(v);
            return;
        }
        for(int i = 0; i < n ; i++) {
            if(!vis[nums[i]]) {
                
                vis[nums[i]] = 1;
                v.push_back(nums[i]);
                
                rec(v, nums);
                
                vis[nums[i]] = 0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        rec({}, nums);
        return res;
    }
};