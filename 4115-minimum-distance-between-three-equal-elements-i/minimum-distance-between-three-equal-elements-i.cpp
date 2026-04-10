class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<vector<int>> pos(101);
        for(int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }
        int ans = 1e3;
        for(int i = 1; i <= 100; i++) {
            if(pos[i].size() < 3) continue;
            for(int j = 0; j < pos[i].size() - 2; j++) {
                int ii = pos[i][j];
                int jj = pos[i][j + 1];
                int kk = pos[i][j + 2];
                int dis = abs(ii - jj) + abs(jj - kk) + abs(kk - ii);
                ans = min(ans, dis);
            }
        }
        return ans == 1e3 ? -1 : ans;
    }
};