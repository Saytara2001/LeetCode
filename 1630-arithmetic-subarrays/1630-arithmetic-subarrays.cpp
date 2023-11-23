class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = size(nums), sz = size(l);
        vector<bool> res;
        for(int i = 0; i < sz; i++) {
            vector<int> v;
            for(int j = l[i]; j <= r[i]; j++) {
                v.push_back(nums[j]);
            }
            sort(begin(v), end(v));
            bool ok = true;
            for(int j = 1; j < size(v) and size(v) > 1; j++) {
                if(v[j] - v[j - 1] != v[1] - v[0]) {
                    ok = 0;
                    break;
                }
            }
            res.push_back(ok);
        }
        return res;
    }
};