class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> vis(100000, 0);
        for(auto vv:arr)
            vis[vv] = 1;
        int cnt = 0,i = 1;
        while(cnt < k) {
            if(!vis[i])
                cnt++;
            i++;
        }
        return --i;
    }
};