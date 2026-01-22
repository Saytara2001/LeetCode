class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        bool sorted = false;
        while(!sorted) {
            vector<int> cur;
            sorted = true;
            int n = nums.size();
            int minSum = INT_MAX, idx = 0;
            for(int i = 1; i < n; i++) {
                sorted &= nums[i - 1] <= nums[i];
                if(nums[i - 1] + nums[i] < minSum) {
                    minSum = nums[i - 1] + nums[i];
                    idx = i - 1;
                }
            }
            if(sorted) break;
            for(int i = 0; i < n; i++) {
                if(i == idx) {
                    cur.push_back(minSum);
                    i++;
                } else {
                    cur.push_back(nums[i]);
                }
            }
            nums = cur;
            ++cnt;
        }

        return cnt;
    }
};