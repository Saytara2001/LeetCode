class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, kk = k, n = size(nums);
        int maxOnes = 0;
        while(r < n) {
            if(l == r and !nums[r] and !k)  {
                l++, r++;
                continue;
            }
            if(nums[r]) {
                r++;
            }else if(!nums[r] and k) {
                r++, k--;
            }else {
                if(l < n and !nums[l]) {
                    k++;
                }
                l++;
            }
            maxOnes = max(maxOnes, r - l);
        }
        return maxOnes;
    }
};