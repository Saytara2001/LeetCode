class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        int p1 = 0, p2 = 0;
        int ans = 0;
        while(p1 < size(g) and p2 < size(s)) {
            if(s[p2] >= g[p1]) {
                p1++;
                ans++;
            }
            p2++;
        }
        return ans;
    }
};