#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> prevIndex(n, -1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prevIndex[i] = j;
                }
            }
        }

        int maxIndex = max_element(dp.begin(), dp.end()) - dp.begin();

        vector<int> result;
        while (maxIndex != -1) {
            result.push_back(nums[maxIndex]);
            maxIndex = prevIndex[maxIndex];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
// class Solution {
// public:
//     int dp[1001][1001];
//     int rec(int i, int lst, vector<int>& nums) {
        
//         if(i == size(nums)) 
//             return 0;
//         if(nums[i] % nums[lst] != 0 and nums[lst] % nums[i] != 0) 
//             return -1;
        
//         int &ret = dp[i][lst];
//         if(~ret)
//             return ret;
        
//         ret = 0;
//         if(i == lst) {
//             ret = rec(i + 1, i + 1, nums);//leave
//             ret = rec(i + 1, i, nums) + 1;
//         }else{
//             ret = rec(i + 1, i, nums) + 1;
//         }
//         return ret;
//     }
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         memset(dp, -1, sizeof dp);
//         return rec(0, 0, nums);
//     }
// };