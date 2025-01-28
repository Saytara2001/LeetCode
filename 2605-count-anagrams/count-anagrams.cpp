class Solution {
public:
    int mod = 1e9 + 7;
    long long fact[100005], modInverse[100005];
    long long mul(long long a, long long b) {
        return ((a % mod) * (b % mod)) % mod;
    }

    long long BinPow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }

    void pre() {
        fact[0] = modInverse[0] = 1LL;
        for (int i = 1; i < 100005; ++i) {
            fact[i] = (1LL * fact[i - 1] * i) % mod;
            modInverse[i] = BinPow(fact[i], mod - 2, mod);
        }
    }
    bool preprocess = false;
    int countAnagrams(string s) {
        if(!preprocess) {
            pre();
            preprocess = true;
        }
        long long res = 1;
        int n = size(s);
        int cnt = 0;
        vector<int> freq(26);
        for(int i = 0; i < n; i++) {
            if(s[i] != ' ') {
                freq[s[i] - 'a']++;
                cnt++;
            }else {
                res = mul(res, fact[cnt]);
                for(int f = 0; f < 26; f++) 
                    if(freq[f] > 0) {
                        res = mul(res, modInverse[freq[f]]);
                        freq[f] = 0;
                    }
                cnt = 0;
            }
        }
        if(cnt > 0) {
            res = mul(res, fact[cnt]);
            for(int f = 0; f < 26; f++) 
                if(freq[f] > 0) {
                     res = mul(res, modInverse[freq[f]]);
                }
        }
       
        return int(res);
    }
};