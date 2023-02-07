class Solution {
public:
    int totalFruit(vector<int>& v) {
        int freq[100005] = {0};
        int l = 0, r = 0, unique = 0, ans = 0;
        int n = v.size();
        while(l <= r and  r < n) {
             if((unique < 2 or freq[v[r]]) and r < n) {
                 if(!freq[v[r]]) unique++;
                 ans = max(ans, r - l + 1);
                 freq[v[r++]]++;
             }else {
                 if(--freq[v[l++]] == 0) unique--;
             }
        }
        return ans;
    }
};