class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 0;
        int cnt = 0, i = 0, sz = size(nums);
        while(sum < n) {
            if(i < sz and sum + 1 >= nums[i]) {
                sum += nums[i++];
            }else {
                sum += sum + 1;
                cnt++;
            }
        }
        return cnt;
    }
};