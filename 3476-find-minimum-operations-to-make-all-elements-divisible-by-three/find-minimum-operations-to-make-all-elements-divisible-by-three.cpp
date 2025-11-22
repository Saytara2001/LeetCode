class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for(auto it: nums) {
            int op = it % 3;
            cnt += min(op, 3 - op);
        }
        return cnt;
    }
};