class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0, cnt = 0;
        int l = 0, r = 0, n = size(nums);
        while(r < n) {
            sum += nums[r++];
            while(l < r and sum * (r - l) >= k) { // loop while still not valid
                sum -= nums[l++];
            }
            if(sum * (r - l) < k)
                cnt += r - l; // add valid subarrays 
        }
        return cnt;
    }
};