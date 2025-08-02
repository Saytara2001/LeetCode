class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int min_all = INT_MAX;
        unordered_map<int, int> freq;
        for(auto x: basket1) {
            ++freq[x];
            min_all = min(min_all, x);
        }
        for(auto y: basket2) {
            --freq[y];
            min_all = min(min_all, y);
        }
        vector<int> rem; // must be even
        for(auto [a, f]: freq) {
            if(f % 2 != 0)
                return -1;
            for(int i = 0; i < abs(f) / 2; i++)
                rem.push_back(a);
        }
        int sz = rem.size();
        sort(rem.begin(), rem.end());
        long long ans = 0;
        for(int i = 0; i < sz / 2; i++) {
            int a = rem[i];
            ans += min(a, min_all * 2);
        }
        return ans;
    }
};