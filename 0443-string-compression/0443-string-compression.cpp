class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt, n = chars.size();
        vector<char> res;
        for(int i = 0; i < n; ) {
            char c = chars[i];
            cnt = 0;
            int j = i;
            while(j < n and c == chars[j]) {
                j++, cnt++, i++;
            }
            res.push_back(c);
            if(cnt > 1) {
                string s = to_string(cnt);
                for(auto ss:s)
                    res.push_back(ss);
            }
        }
        chars.resize(res.size());
        for(int i = 0; i < res.size(); i++)
            chars[i] = res[i];
        return (int)res.size();
    }
};