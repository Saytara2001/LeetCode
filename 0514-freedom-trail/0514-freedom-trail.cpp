class Solution {
public:
    int dp[101][101];
    int rec(int i, int idx, string &ring, string &key) {
        if(idx == size(key)) return 0;
        
        int &ret = dp[i][idx];
        if(~ret) 
            return ret;
        
        ret = INT_MAX;
        for(int j = 0; j < size(ring); j++) {
            if(ring[j] == key[idx]) {
                int dis = min(int(size(ring) - abs(j - i)), abs(j - i));
                ret = min(ret, rec(j, idx + 1, ring, key) + dis + 1);
            }
            
        }
        return ret;
    }
    int findRotateSteps(string ring, string key) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, ring, key);
    }
};