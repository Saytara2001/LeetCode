class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int rem = 0;
        string ans = "";
        while (i >= 0 or j >= 0) {
            int sum = rem;
            if (i >= 0) {
                sum += (a[i--] == '1');
            }
            if (j >= 0) {
                sum += (b[j--] == '1');
            }
            ans += (sum == 2 or sum == 0 ? '0' : '1');
            rem = sum > 1;
        }
        if(rem > 0) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};