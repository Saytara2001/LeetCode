class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> freq(51);
        int len = k - 1;
        for(int i = 0; i < len; i++) {
            ++freq[nums[i]];    
        }
        int l = 0;
        vector<int> res;
        for(int i = len; i < n; i++) {
            ++freq[nums[i]];
            set<pair<int, int>> st;
            int sum = 0;
            for(int f = 1; f <= 50; f++) {
                if(freq[f]) {
                    sum += f * freq[f];
                    st.insert({freq[f], f});
                }
                if(st.size() > x) {
                    sum -= st.begin()->first * st.begin()->second;
                    st.erase(st.begin());
                }
            }
            res.push_back(sum);
            --freq[nums[l++]];
        }
        return res;
    }
};