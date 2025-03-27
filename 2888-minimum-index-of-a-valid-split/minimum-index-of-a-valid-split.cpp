class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int mx = 0;
        unordered_map<int, int > freq;
        for(auto x: nums) {
            if(freq[mx] < ++freq[x])
                mx = x;
        }
        int n = size(nums);
        int cnt = freq[mx];
        for(int i = 0; i < n; i++) {
            if(nums[i] == mx) {
                --cnt;
            }
            int left = freq[mx] - cnt > (i + 1) / 2;
            int right = cnt > (n - i - 1) / 2;
            if(left and right)
                return i;
        }
        return -1;
    }
};