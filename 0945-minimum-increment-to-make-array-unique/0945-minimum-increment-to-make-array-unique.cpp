class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> rem;
        vector<bool> vis(200001);
        for(auto it: nums) {
            if(!vis[it]) {
                vis[it] = true;
            }else {
                rem.push_back(it);
            }
        }
        sort(begin(rem), end(rem));
        int cur = 0, res = 0;
        for(auto it: rem) {
            cur = max(cur, it);
            while(vis[cur]) cur++;
            res += cur - it;
            vis[cur] = true;
        }
        return res;
    }
};