class Solution {
public:
    int freq[26];
    int firstUniqChar(string s) {
        for(auto ss:s){
            freq[ss-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a'] == 1){
                return i;
            }
        }
     return -1;
    }
};