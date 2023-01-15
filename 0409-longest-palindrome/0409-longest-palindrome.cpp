class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(auto ss:s) mp[ss]++;
        
        int longest_length = 0, odd = 0;
        
        for(auto it:mp){
            longest_length += it.second & 1 ? it.second-1 : it.second;
            odd |= it.second & 1;
        }
        return longest_length + odd;
    }
};