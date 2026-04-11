class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> pos;
        for(int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }
        int ans = 1e9;
        for(auto [x, vec]: pos) {
            if(vec.size() < 3) continue;
            for(int j = 0; j < vec.size() - 2; j++) {
                int ii = vec[j];
                int jj = vec[j + 1];
                int kk = vec[j + 2];
                int dis = 2 * kk - 2 * ii;
                ans = min(ans, dis);
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};