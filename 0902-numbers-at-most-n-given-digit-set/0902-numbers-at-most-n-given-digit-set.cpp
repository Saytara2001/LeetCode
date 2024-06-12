#define ll long long 
vector<int> pref(10, 0);
vector<bool> vis(10, false);
string s;

class Solution {
public:
    
    ll burn(vector<ll> &dp) {
        
        ll res = 0;
        int n = s.size();
        
        //add the all result less than the given number (x)
        for (int i = 0; i < n; ++i) {
            res += dp[i];
        }
        
        int prev = 0;
        for (int i = 0; i < n; ++i) {
            
            int digit = s[i] - '0';
            // if(digit == 0) return res;
            int rem = n - i - 1;
            
            //get combination for this number
            int below = pref[max(digit - 1, 0)];
            
            //get how many combination for the answer
            res += (digit == 0 ? 0 : dp[rem] * below);
            
            //we cann't continue so the two digits are the same
            if (!vis[digit]) {
                return res;
            }
            prev = digit;
        }
        return res + 1; //1 for number itself (x)
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        s = to_string(n);
        pref.assign(10, 0);      
        vis.assign(10, 0);

        for(auto it: digits) {
            int d = it[0] - '0';
            vis[d] = true;
            pref[d]++;
        }
        
        vector<ll> dp(12);
        dp[0] = 1;
        
        //to get how many numbers will be used from 0 to digit
        for (int i = 1; i < 10; ++i) {
            pref[i] += pref[i - 1];
        }
        
        int x = size(digits);
        for (int i = 1; i < 12; ++i) {
            dp[i] = dp[i - 1] * x;
        }
        
        return burn(dp) - 1;
    }
};