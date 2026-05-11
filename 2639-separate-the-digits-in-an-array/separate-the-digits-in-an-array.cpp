class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (auto x : nums) {
            int y = x;
            bool flag = false;
            for(int i = 100000; i >= 1; i /= 10) {
                int d = int(y / i) % 10;
                if(d > 0) {
                    flag = true;
                    res.push_back(d);
                } else if(flag and d == 0) {
                    res.push_back(d);
                }
            }
        }
        return res;
    }
};