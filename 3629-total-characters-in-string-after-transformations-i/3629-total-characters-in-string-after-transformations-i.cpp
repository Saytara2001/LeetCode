class Solution {
public:
    const int mod = 1e9 + 7;
    long long add(long long a, long long b) {
        return (a % mod + b % mod) % mod;
    }
    int lengthAfterTransformations(string s, int t) {
        
        vector<long long> freq(26, 0);
        int n = size(s);
        for(auto c: s) ++freq[c - 'a'];
        
        while(t--) {
            long long lstFreq = 0;
            for(int i = 0; i < 25; i++) {
                long long nxt = (freq[i] - lstFreq + mod) % mod;
                freq[i + 1] = add(freq[i + 1], nxt);
                freq[i] = lstFreq;
                freq[i] %= mod;
                lstFreq = nxt;
            }
            freq[0] = add(freq[0], freq[25] - lstFreq + mod);
            freq[1] = add(freq[1], freq[25] - lstFreq + mod);
            freq[25] = lstFreq;
            freq[25] %= mod;
        }
        
        long long sum = 0;
        for(int i = 0; i < 26; i++) 
            sum = add(sum , freq[i]);
        
        return sum;
    }
};