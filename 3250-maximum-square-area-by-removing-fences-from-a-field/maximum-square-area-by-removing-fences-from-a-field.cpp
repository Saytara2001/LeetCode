class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences) {
        unordered_map<int, bool> vis;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(begin(hFences), end(hFences));
        sort(begin(vFences), end(vFences));
        for (int i = 0; i < hFences.size(); i++) { // 3e5
            for (int j = i + 1; j < hFences.size(); j++) {
                int dis = hFences[j] - hFences[i];
                vis[dis] = true;
            }
        }
        const int mod = 1e9 + 7;
        long long ans = -1;
        for (int i = 0; i < vFences.size(); i++) { // 3e5
            for (int j = i + 1; j < vFences.size(); j++) {
                int dis = vFences[j] - vFences[i];
                if(vis[dis]) {
                    ans = max(ans, 1LL * dis * dis);
                }
            }
        }
        return ans % mod;
    }
};