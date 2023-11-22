class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        vector<int> res;
        vector<vector<int>> v(2e5);
        
        for(int i = size(nums) - 1; i >= 0 ; i--) {
            for(int j = size(nums[i]) - 1; j >= 0 ; j--) {
                v[i + j].push_back(nums[i][j]);
            }
        }
        
        for(int i = 0; i < 2e5; i++) {
            for(auto it: v[i])
                res.push_back(it);
        }
        return res;
    }
};