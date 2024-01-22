class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = size(nums);
        int missed = n, rep = 0;
        int cur = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == cur) {
                cur++;
            }else if(nums[i] > cur) {
                missed = cur++;
                i--;
            }else if(nums[i] < cur) {
                rep = nums[i];
            }
        }
        vector<int> res {rep, missed};
        return res;
    }
};