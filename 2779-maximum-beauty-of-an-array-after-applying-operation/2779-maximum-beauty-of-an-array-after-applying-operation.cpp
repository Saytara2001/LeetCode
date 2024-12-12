class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> pref(1e5 + 2);
        for(auto num: nums) {
            pref[max(num - k, 0)]++;
            pref[min(num + k + 1, int(1e5 + 1))]--;
        }
        
        int maxBeauty = pref[0];
        for(int i = 1; i <= 1e5; i++) {
            pref[i] += pref[i - 1];
            maxBeauty = max(maxBeauty, pref[i]);
        }
            
        return maxBeauty;
    }
}; 