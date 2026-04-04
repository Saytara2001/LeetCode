class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int margin = n / rows + 1;
        string ans = "";
        int last = (n + rows - 1) / rows;
        for(int i = 0; i < last; i++) {
            int cur = 0;
            while(i + (margin * cur) < n) {
                ans += encodedText[i + (margin * cur)];
                ++cur;
            }
        }
        while(ans.size() and ans.back() == ' ') ans.pop_back();
        return ans;
    }
};