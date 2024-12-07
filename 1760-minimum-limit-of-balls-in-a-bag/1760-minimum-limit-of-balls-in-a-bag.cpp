class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int l = 1, r = 1e9, n = size(nums);
        
        auto valid = [&](int mid) {
            int all = maxOperations;
            for(int i = 0; i < n; i++) {
                
                int op = (nums[i] + mid - 1) / mid;
                all -= max(op - 1, 0);
                
                if(all < 0)
                    return false;
            }
            return all >= 0;
        };
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(valid(mid)) {
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        
        return r;
    }
};