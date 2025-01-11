class Solution {
public:
    bool canConstruct(string s, int k) {

        vector<int> freq(26);
        for(auto c: s) {
            freq[c - 'a']++;
        }

        int even = 0, odd = 0;
        for(auto f: freq) {
            even += f / 2;
            odd += f & 1;
        } 
        if(odd > k or odd + 2 * even < k)
            return false;
        
        return true;
    }
};