class Solution {
public:
    int maxSum = 0, n;
    vector<int> best, cur;
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
    void build_output(int i, int rem, int k, vector<int>& nums) {

        if(!rem) {
            best = min(best, cur);
            return;
        }
            

        if(i >= n)
            return;
        
        int ch1 = rec(i + 1, rem, k, nums);
        int ch2 = 0;

        if(i + k <= n) {
            int sum = pref[i + k] - pref[i];
            ch2 = rec(i + k, rem - 1, k, nums) + sum;
        }

        int &ret = dp[i][rem];
        if(ret == ch1) {
            build_output(i + 1, rem, k, nums);
        }
        if(ret == ch2 and i + k <= n) {
            cur.push_back(i);
            build_output(i + k, rem - 1, k, nums);
            cur.pop_back();
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        
        n = size(nums);
        memset(dp, -1, sizeof dp);
        pref.resize(n + 2);
        cur.clear();
        best.push_back(1000000);
        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        cout << rec(0, 3, k, nums) <<endl;
        build_output(0, 3, k, nums);

        return best;
    }
};