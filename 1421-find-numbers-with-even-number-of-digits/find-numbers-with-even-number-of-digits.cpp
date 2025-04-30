class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto x: nums) {
            int d = 0, y = x;
            while(y > 0) {
                ++d;
                y /= 10;
            }
            cnt += d % 2 == 0;
        }
        return cnt;
    }
};