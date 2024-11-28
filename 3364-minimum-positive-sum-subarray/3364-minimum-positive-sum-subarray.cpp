class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mn = 1e9;
        for(int i = 0; i < size(nums); i++) {
            int sum = 0;
            int left = i;
            for(int j = i; j < size(nums); j++) {
                sum += nums[j];
                int len = j - left + 1;
                if(len > r)
                    sum -= nums[left++];
                if(sum > 0 and len >= l and len <= r) 
                    mn = min(mn, sum);
            }
        }
        return mn == 1e9 ? -1 : mn;
    }
};