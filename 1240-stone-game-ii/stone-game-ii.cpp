class Solution {
public:
    int dp[100][201][2];
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof dp);
        // vector<vector<vector<int>>> dp(n);
        // for(int i = 0; i < n; i++) {
        //     dp[i].resize(n);
        //     for(int j = 0; j < n; j++) {
        //         dp[i][j].resize(2);
        //         for(int k = 0; k < 2; k++) {
        //             dp[i][j][k] = -1;
        //         }
        //     }
        // }
        function<int(int, int, bool)> rec = [&](int i, int M, bool alice) {
            // cout << i <<" "<< M <<" "<<alice <<endl;
            if(i == n) 
                return 0;

            int &ret = dp[i][M][alice];
            if(~ret)
                return ret;

            ret = (alice ? -1 : 1e6);
            if(alice) {
                for(int stones = 1; stones <= 2 * M; stones++) {
                    int cost = 0, lst = min(i + stones - 1, n - 1);
                    int len = lst - i + 1;
                    for(int k = i; k <= lst ; k++) {
                        cost += piles[k];
                    }
                    ret = max(ret, rec(lst + 1, max(M, len), !alice) + cost);
                    for(int k = i; k <= lst ; k++) {
                        cost -= piles[k];
                    }
                }
            } else {
                 for(int stones = 1; stones <= 2 * M; stones++) {
                    int lst = min(i + stones - 1, n - 1);
                    int len = lst - i + 1;
                    ret = min(ret, rec(lst + 1, max(M, len), !alice));
                }
            }

            return ret;
        };

        return rec(0, 1, 1);
    }
};