class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        auto get = [&](string& s, vector<int>& v) {
            int num = 0;
            for(auto x: s) {
                if(x == '.') {
                    v.push_back(num);
                    num = 0;
                    continue;
                }
                int d = x - '0';
                num = num * 10 + d;
            }
            v.push_back(num);
        };
        get(version1, v1);
        get(version2, v2);
        int p1 = 0, p2 = 0;
        int n = size(v1), m = size(v2);
        while(p1 < n or p2 < m) {
            if(p1 < n and p2 < m) {
                if(v1[p1] > v2[p2]) return 1;
                if(v1[p1] < v2[p2]) return -1;
                ++p1, ++p2;
            } else if(p1 < n) {
                if(v1[p1++] == 0) continue;
                return 1;
            } else {
                if(v2[p2++] == 0) continue;
                return -1;
            }
        }
        return 0;
    }
};