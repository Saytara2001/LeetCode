class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int min_all = INT_MAX;
        unordered_map<int, int> freq1, freq2, all;
        for(auto x: basket1) {
            ++freq1[x];
            ++all[x];
            min_all = min(min_all, x);
        }
        for(auto y: basket2) {
            ++freq2[y];
            ++all[y];
            min_all = min(min_all, y);
        }
        vector<int> rem; // must be even
        for(auto [a, f]: all) {
            if(f & 1)
                return -1;
            if(freq1[a] == freq2[a]) continue;
            int diff = abs(freq1[a] - freq2[a]);
            for(int i = 0; i < diff / 2; i++)
                rem.push_back(a);
        }
        int sz = rem.size();
        if(sz == 0) 
            return 0;
        sort(rem.begin(), rem.end());
        int min_val = rem.front();
        long long ans = 1LL * min_val * (sz - 1);
        long long ans2 = 0;
        for(int i = 0; i < sz / 2; i++) {
            int a = rem[i];
            int b = rem[sz - i - 1];
            ans2 += min(a, min_all * 2);
        }
        return min(ans, ans2);
    }
};