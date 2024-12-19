class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int cur = 0, cnt = 0, lst = 0;
        int n = size(arr);
        vector<bool> vis(n);
        
        for(int i = 0; i < n; i++) {
            vis[arr[i]] = true;
            bool flag = true;
            for(int j = lst; j <= i; j++) {
                flag &= vis[j];
            }
            if(flag) {
                ++cnt;
                lst = i + 1;
            }
        }
        
        return cnt;
    }
};