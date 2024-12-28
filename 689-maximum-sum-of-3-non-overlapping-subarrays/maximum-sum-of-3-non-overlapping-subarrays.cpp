class Solution {
public:
    int maxSum = 0, n;
    vector<int> cur;
    int dp[20000][4];
    vector<int> pref;
    int rec(int i, int rem, int k, vector<int>& nums) {

        if(!rem) {
            return 0;
        }

        if(i >= n)
            return -1e9;

        int &ret = dp[i][rem];
        if(~ret)
            return ret;
        
        ret = max(ret, rec(i + 1, rem, k, nums));

        if(i + k <= n) {
            int sum = pref[i + k] - pref[i];
            ret = max(ret, rec(i + k, rem - 1, k, nums) + sum);
        }
        
        return ret;
    }
    vector<int> build_output(int i, int rem, int k, vector<int>& nums) {
        
        vector<int> best {1000000};

        if(!rem) {
            best = min(best, cur);
            return best;
        }
            
        if(i >= n)
            return {1000000};
        
        int ch1 = rec(i + 1, rem, k, nums);
        int ch2 = 0;

        if(i + k <= n) {
            int sum = pref[i + k] - pref[i];
            ch2 = rec(i + k, rem - 1, k, nums) + sum;
        }

        int &ret = dp[i][rem];
        if(ret == ch1) {
            best = min(best, build_output(i + 1, rem, k, nums));
        }
        if(ret == ch2 and i + k <= n) {
            cur.push_back(i);
            best = min(best, build_output(i + k, rem - 1, k, nums));
            cur.pop_back();
        }
        return best;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        
        n = size(nums);
        memset(dp, -1, sizeof dp);
        pref.resize(n + 2);

        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        cout << rec(0, 3, k, nums) <<endl;

        return build_output(0, 3, k, nums);
    }
};