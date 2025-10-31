class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        vector<int> vis(n);
        for(int i = 0; i < n; i++) {
            if(vis[nums[i]]) res.push_back(nums[i]);
            vis[nums[i]] = true;
        }
        return res;
    }
};