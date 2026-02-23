class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        bitset<1048576> vis;
        int mask = (1 << k) - 1;
        int need = 1 << k;
        int hash = 0;
        for(int i =0; i < n; i++) {
            hash = ((hash << 1) & mask) | (s[i] & 1);
            if(i >= k - 1 and !vis[hash]) {
                vis[hash] = 1;
                --need;
                if(need == 0) return true;
            }
        }
        return false;
    }
};