class Solution {
public:
    int possibleStringCount(string word) {
        int cnt = 0, n = size(word);
        for(int i = 0; i < n; i++) {
            int cur = i;
            while(cur < n and word[i] == word[cur]) ++cur;
            if(cur - i > 1) {
                if(cnt > 0) --cnt;
                cnt += cur - i;
            }
            i  = cur - 1;
        }
        return max(cnt, 1);
    }
};