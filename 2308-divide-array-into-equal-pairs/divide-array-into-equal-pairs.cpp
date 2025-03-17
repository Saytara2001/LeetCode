class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        int mx = 0;
        vector<int> freq(501);

        for(auto x: nums) {
            freq[x]++;
            mx = max(mx, x);
        }

        int ok = true;
        for(int i = 0; i < mx + 1; i++)
            ok &= (freq[i] % 2 == 0);
        
        return ok;
    }
};