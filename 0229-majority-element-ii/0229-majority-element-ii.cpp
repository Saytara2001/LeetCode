class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //n log n
        vector<int> v;
        sort(begin(nums), end(nums));
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int cur = i;
            while(cur < n and nums[cur] == nums[i]) {
                cur++;
            }
            if(cur - i > n / 3)
                v.push_back(nums[i]);
            i = cur - 1;
        }
        return v;
    }
};