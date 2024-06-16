class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 0;
        int cnt = 0;
        for(int i = 0; i < size(nums); i++) {
            if(sum + 1 >= nums[i]) {
                sum += nums[i];
            }else {
                while(sum + 1 < nums[i] and sum < n) {
                    sum += sum + 1;
                    cnt++;
                }
                sum += nums[i];
            }
        }
        while(sum < n) {
            sum += sum + 1;
            cnt++;
        }
        return cnt;
    }
};