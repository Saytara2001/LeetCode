class Solution {
public:
    int mod = 1000000007;
    int add(int a, int b) {
        return (a % mod + b % mod) % mod;
    }
    int dp[101][201], st, end;
    int rec(int i, int fuel, vector<int>& locations) {
        
        // if(i == end)
        //     return 1;
        
        
        int &ret = dp[i][fuel];
        if(~ret)
            return ret;
        
        int ans = i == end ? 1 : 0;
        // ret = 0;
        for(int k = 0; k < size(locations); k++) {
            int dis = abs(locations[k] - locations[i]);
            if(k != i and dis <= fuel) {
                // ret = add(ret, rec(i, fuel, locations)); //leave
                ans = add(ans, rec(k, fuel - dis, locations)); //take
            }
        }
        return ret = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        st = start, end = finish;
        memset(dp, -1, sizeof dp);
        return rec(st, fuel, locations);
    }
};